def month_day_valid(month, day):
    """month and day validation"""
    months = list(range(1, 13))
    days = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    month_day = dict(zip(months, days))
    return (month in month_day) and (day > 0 and day <= month_day[month])