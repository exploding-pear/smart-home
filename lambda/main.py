import boto3
import json

def handler(event, context):
	for key in event.keys():
		print("{key}: {value}".format(key=key, value=event[key]))
	
	if not event['body']['status']:
		message = json.loads('{ "message": "missing status" }')
	
	print(event['body']['status'])

	return(message)