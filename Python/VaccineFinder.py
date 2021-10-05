# This program takes user input for date and pincode and shows available vaccine slots:
import requests
pincode = input("Enter area pincode: ")
date = input("Enter date (DD-MM-YYYY): ")
API_URL = f"https://cdn-api.co-vin.in/api/v2/appointment/sessions/public/findByPin?pincode={pincode}&date={date}"
response = requests.get(API_URL).json()
i = 0
for slot in response["sessions"]:
    i += 1
    print(
        f'Slot #{i}: Name - {slot["name"]}, Vaccine - {slot["vaccine"]}, Available - {slot["available_capacity"]}, Price - {slot["fee"]}')
