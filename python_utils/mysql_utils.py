"""Some mysql utils.

Some mysql utils.
"""
import logging
import pymysql

logging.basicConfig(format="%(threadName)s %(asctime)s %(levelname)s line %(lineno)s : %(message)s",
                    datefmt="%Y-%m-%d %H:%M:%S", level=logging.INFO)
logger = logging.getLogger(__name__)

def getMysqlConn(host, port, user, password, db):
    """Create one mysql conn.

    Create one mysql conn.
    """
    conn = pymysql.connect(host=host, port=port, user=user,
                           password=password, db=db, charset='utf8')
    return conn


def selectMysql(conn, sql):
    """Query mysql.

    Query mysql.
    """
    conn.ping()
    ret = None
    try:
        with conn.cursor() as cursor:
            logger.info("exec mysql progressing: **{}**".format(sql))
            cursor.execute(sql)
            ret = cursor.fetchall()
            logger.info(f"mysql ret: *{ret}*")
            logger.info("exec mysql success: **{}**".format(sql))
    except Exception as e:
        conn.close()
        logger.exception(e)
    return ret


def updateMysql(conn, sql):
    """Update mysql.

    Update mysql.
    """
    conn.ping()
    ret = None
    try:
        with conn.cursor() as cursor:
            logger.info("exec mysql progressing: **{}**".format(sql))
            cursor.execute(sql)
            conn.commit()
            logger.info("exec mysql success: **{}**".format(sql))
    except Exception as e:
        conn.close()
        logger.exception(e)
    return ret
