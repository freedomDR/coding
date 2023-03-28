"""Some mysql utils.

Some mysql utils.
"""
import logging
import pymysql

logging.basicConfig(format="%(threadName)s %(asctime)s %(levelname)s line %(lineno)s : %(message)s",
                    datefmt="%Y-%m-%d %H:%M:%S", level=logging.INFO)


def get_mysql_conn(host, port, user, password, db):
    """Create one mysql conn.

    Create one mysql conn.
    """
    conn = pymysql.connect(host=host, port=port, user=user,
                           password=password, db=db, charset='utf8')
    return conn


def select_mysql(conn, sql):
    """Query mysql.

    Query mysql.
    """
    conn.ping()
    ret = None
    try:
        with conn.cursor() as cursor:
            logging.info("exec mysql progressing: **{}**".format(sql))
            cursor.execute(sql)
            ret = cursor.fetchall()
            logging.info(f"mysql ret: *{ret}*")
            logging.info("exec mysql success: **{}**".format(sql))
    except Exception as e:
        conn.close()
        logging.exception(e)
    return ret


def update_mysql(conn, sql):
    """Update mysql.

    Update mysql.
    """
    conn.ping()
    ret = None
    try:
        with conn.cursor() as cursor:
            logging.info("exec mysql progressing: **{}**".format(sql))
            cursor.execute(sql)
            conn.commit()
            logging.info("exec mysql success: **{}**".format(sql))
    except Exception as e:
        conn.close()
        logging.exception(e)
    return ret
