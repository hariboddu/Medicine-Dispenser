# Medicine-Dispenser and Medicine Expiry Detector

Features:

Schedules pills according to the users requirements at different times of the day.

Setup to automatically open and close appropriate slots, using arduino and
servomotors and a buzzer to notify the patient at a set time.

Expiry Detector:

Snapshot of medicine with webcam is taken and send it to pi environment for OCR.

Using deep learning based Tesseract algorithm on a pi environment,expiry date is extracted
and check with current date to obtain expiry status of medicine.
