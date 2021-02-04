#!/bin/bash

set -Eeuo pipefail


SOURCES=~/utils
TARGET=~/.local/bin


if [[ ! -d "$SOURCES" ]]; then
    echo "Required directory: $SOURCES not found."
    exit 1
fi


if [[ ! -d "$TARGET" ]]; then
    mkdir -p "$TARGET"
fi

(cd "$SOURCES"; cp * -t "$TARGET")

echo "All finish!"
exit 0