import boto3
import json

def handler(event, context):
	print(type(event))
	print(type(context))