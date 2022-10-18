
import logging
from rich.logging import RichHandler

logging.basicConfig(format="%(threadName)s line %(lineno)s : %(message)s", datefmt='%Y-%m-%d %H:%M:%S', level=logging.DEBUG, handlers=[RichHandler(omit_repeated_times=False, log_time_format="[%Y-%m-%d %H:%M:%S]")])

logger = logging.getLogger()
logging.info("hello world 123123 --------- POST")
logging.debug("hello world")
logging.warning("hello world")
logging.error("hello world")
