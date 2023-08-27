#!/usr/bin/env bash

git fetch --tags
VERSION="$(git describe --tags "$(git rev-list --tags --max-count=1)")"
git switch -c "$CORE_VERSION"
echo "$VERSION" > VERSION.txt
sed "s/%%VERSION%%/${VERSION}/" samd-arduino.json
sed "s/%%VERSION%%/${VERSION}/" ../platform.txt
