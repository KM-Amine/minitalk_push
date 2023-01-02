#!/bin/bash

SERVERID=$(top -l 1 | grep server_bonus | awk '{print $1}')
for i in {1..100000}
do
		./client_bonus $SERVERID  "📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗"
done