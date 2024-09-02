-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE day=28 AND month=7 AND year=2020 AND street = "Chanberlin Street";

--Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today
--with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

SELECT transcript FROM interviews WHERE day=28 AND month=7 AND year=2020;

--transcript
--“Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my
--assistance in the case of the Irene Adler papers.” “I suppose,” said Holmes, “that when Mr. Windibank came back from France he was very
--annoyed at your having gone to the ball.” “You had my note?” he asked with a deep harsh voice and a strongly marked German accent.
--“I told you that I would call.” He looked from one to the other of us, as if uncertain which to address. Sometime within ten minutes of
--the theft, I saw the thief get into a car in the courthouse parking lot and drive away. If you have security footage from the courthouse
--parking lot, you might want to look for cars that left the parking lot in that time frame.I don't know the thief's name, but it was someone
--I recognized. Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there
--withdrawing some money.As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call,
--I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on
--the other end of the phone to purchase the flight ticket.


SELECT name FROM people WHERE license_plate IN (SELECT courthouse_security_logs.license_plate FROM courthouse_security_logs
WHERE day=28 AND month=7 AND year=2020 AND hour = 10 AND minute >=15 AND minute <= 25);

--Range of minutes is defined becasue theft was on 10:15 and as mentioned above some where between 10 minutes
--used in parking lot so as not accurate time is given so we are defining range here
--Patrick
--Ernest
--Amber
--Danielle
--Roger
--Elizabeth
--Russell
--Evelyn

SELECT name FROM people WHERE id IN
(SELECT bank_accounts.person_id FROM bank_accounts WHERE account_number IN
(SELECT atm_transactions.account_number FROM atm_transactions WHERE id IN
(SELECT id FROM atm_transactions WHERE year=2020 AND month=7 AND day=28 AND
atm_location="Fifer Street" AND transaction_type="withdraw")));

--These are the persons who did atm transactions on that day:
--Bobby
--Elizabeth
--Victoria
--Madison
--Roy
--Danielle
--Russell
--Ernest

--Persons who left the court house and have atm transactions on that day are:

--Ernest
--Danielle
--Elizabeth
--Russel

SELECT name FROM people WHERE passport_number IN(SELECT passengers.passport_number
FROM passengers WHERE flight_id IN(SELECT id FROM flights WHERE year=2020 AND month=7
AND day=29 ORDER BY hour,minute LIMIT 1));

--LIMIT 1 to get information of first flight and we order by hour,minute because they
--have to take the earliest flight day=29 because the flight is on next day

--These are the persons having flight
--Bobby
--Roger
--Madison
--Danielle
--Evelyn
--Edward
--Ernest
--Doris

--But because of above mentioned statements and proofs the theft may be someone of:

--Danielle
--Ernest

SELECT name FROM people WHERE phone_number IN
(SELECT caller FROM phone_calls WHERE year=2020 AND day=28 AND month=7 AND duration < 60);

--These are the persons who have called some for less than 60 seconds on that day
--Bobby
--Roger
--Victoria
--Madison
--Russell
--Evelyn
--Ernest
--Kimberly

--As our theft may be one of either Danielle or Ernest
--So ,From above result Ernest is the person who stole cs50 duck

SELECT city FROM airports WHERE id IN(
SELECT destination_airport_id FROM flights WHERE day=29 AND month=7 AND year=2020 ORDER BY hour,minute LIMIT 1);

--London (Ernest wants to leave)

SELECT name FROM people WHERE phone_number IN(
SELECT receiver FROM phone_calls WHERE day=28 AND month=7 AND year=2020 AND duration < 60
AND caller IN (SELECT phone_number FROM people WHERE name = "Ernest"));

--Berthhold person who help the suspect(Ernest)