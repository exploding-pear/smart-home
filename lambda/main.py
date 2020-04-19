import boto3
import json

def handler(event, context):
	for key in event.keys():
		print("{key}: {value}".format(key=key, value=event[key]))
	
	message = json.loads('{"message": "hello world!"}')

	print(type(event['body']))

	return(message)