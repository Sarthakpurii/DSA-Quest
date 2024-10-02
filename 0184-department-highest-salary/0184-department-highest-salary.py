import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    if employee.empty or department.empty:
        return pd.DataFrame(columns=['Department','Employee','Salary'])
    return employee.merge(department,left_on='departmentId',right_on='id').groupby('departmentId').apply(lambda x:x[x['salary']==x['salary'].max()]).reset_index(drop=True)[['name_y','name_x','salary']].rename(columns={'name_y':'Department','name_x':'Employee','salary':'Salary'})