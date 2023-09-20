def quiz_message(grade):
	if grade < 50:
		outcome = 'failed'
	else:
		outcome = 'passed'
	print('You', outcome, 'the quiz with a', grade, '!')

quiz_message(40)
quiz_message(75)
