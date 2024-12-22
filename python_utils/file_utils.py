"""Some mysql utils.

Some mysql utils.
"""
import logging
import pymysql
import tempfile

logging.basicConfig(format="%(threadName)s %(asctime)s %(levelname)s line %(lineno)s : %(message)s",
                    datefmt="%Y-%m-%d %H:%M:%S", level=logging.INFO)
logger = logging.getLogger(__name__)

def genetateRandomDirectory(parent_directory):
    tempfile.
    