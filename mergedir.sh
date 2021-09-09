#!/bin/bash
mkdir -p "$1"
for x in $1-*
do
    cp "$x/$x".{docx,cpp,png} "$1"
done
zip -q -r "$1.zip" "$1" && \
rm -rf "$1"
