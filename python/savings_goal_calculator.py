import datetime
import calendar

goal_name = input("Please Enter Your Goal Name: ")
goal = float(input("Please Enter Your Goal Amount: "))
monthly_savings = float(input("Please Enter Your Monthly Savings Amount: "))

today = datetime.date.today()
days_in_current_month = calendar.monthrange(today.year, today.month)[1]
days_till_end_of_month = days_in_current_month - today.day

start_date = today + datetime.timedelta(days=days_till_end_of_month + 1)
end_date = start_date

while goal > 0:
    month_year = (0 / 12) * goal
    goal += month_year
    goal -= monthly_savings

    goal = round(goal, 2)
    if goal < 0:
        goal = 0

    print(end_date, goal)

    days_in_current_month = calendar.monthrange(
        end_date.year, end_date.month)[1]
    end_date = end_date + datetime.timedelta(days=days_in_current_month)
