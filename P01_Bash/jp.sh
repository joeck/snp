#!/bin/bash
# TODO: please describe the purpose and usage of the script
timestamp=$(date '+%Y%m%e-%H%M%S')
# TODO: produce YYYYMMDD-HHMMSS forma
location=${PWD////_}
# get PWD value and replace all / by _
name="backup_${location}_${timestamp}" # put together the elements of the name
fullname=/tmp/$name.tgz # the full file name
tar czvf $fullname . # create an archive of the current directory
if [ $? ] # check outcome ...
then
echo "SUCCESS: $fullname"
else
echo "FAILED: $fullname"
fi
