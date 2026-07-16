#!/bin/bash

set -e

DISPLAY_NUM=:99
XEPHYR_PID=""

cleanup() {
    echo "Finalizando..."
    if [ -n "$XEPHYR_PID" ] && kill -0 "$XEPHYR_PID" 2>/dev/null; then
        kill "$XEPHYR_PID"
        wait "$XEPHYR_PID" 2>/dev/null || true
    fi
}

trap cleanup EXIT INT TERM

echo "Iniciando Xephyr em $DISPLAY_NUM..."

Xephyr "$DISPLAY_NUM" -screen 1280x720 -host-cursor &
XEPHYR_PID=$!

sleep 2

export DISPLAY=$DISPLAY_NUM

echo "Executando make clean all..."
make clean all

echo "Executando ./build/main..."
./build/file/main