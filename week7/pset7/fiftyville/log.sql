-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = "Chamberlin Street";
/*
description
Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
Interviews were conducted today with three witnesses who were present at the time —
each of their interview transcripts mentions the courthouse.
*/


SELECT name, transcript
FROM interviews
WHERE month = 7 AND day = 28
AND transcript LIKE "%courthouse%";
/*
name | transcript
Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car
       in the courthouse parking lot and drive away. If you have security footage from
       the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning,
         before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw
         the thief there withdrawing some money.
Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
         In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
         The thief then asked the person on the other end of the phone to purchase the flight ticket.
*/


-- The Suspect thief is:
WITH suspect_account_number AS (
  SELECT account_number
  FROM atm_transactions
  WHERE month = 7 AND day = 28
  AND atm_location = "Fifer Street"
  AND transaction_type = "withdraw"
),
suspect_person_id AS (
  SELECT person_id
  FROM bank_accounts
  WHERE account_number IN suspect_account_number
),
suspect_license_plate AS (
  SELECT license_plate
  FROM courthouse_security_logs
  WHERE month = 7 AND day = 28 AND hour = 10
  AND minute BETWEEN 10 AND 20
),
suspect_phone_calls AS (
  SELECT caller
  FROM phone_calls
  WHERE month = 7 AND day = 28
)
SELECT *
FROM people
WHERE id IN suspect_person_id
AND license_plate IN suspect_license_plate
AND phone_number IN suspect_phone_calls;
/*
d | name | phone_number | passport_number | license_plate
686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
*/



-- Suspect accomplice table
WITH suspect_accomplice_phone_number AS (
  SELECT receiver
  FROM phone_calls
  WHERE month = 7 AND day = 28
  AND caller = "(367) 555-5533"
  AND duration <= 60
)
SELECT *
FROM people
WHERE phone_number IN suspect_accomplice_phone_number;
/*
864400 | Berthold | (375) 555-8161 |  | 4V16VO0
*/

SELECT *
FROM courthouse_security_logs
WHERE month = 7 AND day = 28
AND license_plate IN ("V4C670D", "81MZ921", "4V16VO0", "10I5658");
/*
id | year | month | day | hour | minute | activity | license_plate
248 | 2020 | 7 | 28 | 8 | 50 | entrance | 4V16VO0
249 | 2020 | 7 | 28 | 8 | 50 | exit | 4V16VO0
*/


-- The thief escape to:
WITH earliest_flight_id AS (
  SELECT destination_airport_id
  FROM flights
  WHERE month = 7 AND day = 29
  AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville")
  ORDER BY hour
  LIMIT 1
)
SELECT * FROM airports WHERE id IN earliest_flight_id;
/*
id | abbreviation | full_name | city
4 | LHR | Heathrow Airport | London
*/
