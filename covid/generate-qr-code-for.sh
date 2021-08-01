#!/usr/bin/env sh

# Generate a qr code for the given text (e.g. generate link qr codes)
# ./generate-qr-code-for.sh "fdroid-app.svg" "https://f-droid.org/en/packages/de.corona.tracing/"

out="$1"
text="$2"

qrencode -s 8 -o "$out" -t svg -- "$text"
