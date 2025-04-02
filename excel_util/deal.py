
import logging
import pandas as pd
## pip intall pandas openpyxl

logging.basicConfig(format='%(threadName)s %(asctime)s %(levelname)s line %(lineno)s : %(message)s',datefmt='%Y-%m-%d %H:%M:%S', level=logging.INFO)
logger = logging.getLogger(__name__)

def readExcel(filename):
    return pd.read_excel(filename)


if (__name__ == "__main__"):
    select_df = readExcel("/workspace/coding/excel_util/select.xlsx")
    target_df = readExcel("/workspace/coding/excel_util/P020250223602708033967.xlsx")
    select_df_rows, select_df_columns = select_df.shape
    target_df_rows, target_df_columns = target_df.shape
    for i in range(1, select_df_rows):
        job_name = select_df.iloc[i, 0:3].values[1].replace("\n", "")
        job_limit = select_df.iloc[i, 0:3].values[2]
        for ii in range(target_df_rows):
            if (job_name in target_df.iat[ii, 0] and job_limit == target_df.iat[ii, 1]):
                print(f"{job_name} {job_limit} 招聘人数: {target_df.iat[ii, 2]} 填报信息人数: {target_df.iat[ii, 3]} 初审通过人数: {target_df.iat[ii, 4]} 缴费人数: {target_df.iat[ii, 5]}")
    