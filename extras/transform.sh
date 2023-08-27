#!/usr/bin/env bash

git fetch --tags
VERSION="$(<VERSION.txt)"
git switch -c "$VERSION"
sed -i "s/%%VERSION%%/${VERSION}/" samd-arduino.json
sed -i "s/%%VERSION%%/${VERSION}/" ../platform.txt
