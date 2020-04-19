import boto3
import json

def handler(event, context):
	for key in event.keys():
		print("{key}: {value}".format(key=key, value=event[key]))
	return("{ \"message\": \"hello world!\"}")