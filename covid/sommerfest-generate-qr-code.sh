#!/usr/bin/env bash

set -euo pipefail

npm install cwa-event-qr-code

# type 9 = kulturelle Veranstaltung
./node_modules/.bin/cwa-event-qr-code file \
  --description "OpenLab Augsburg Sommerfest 2021" \
  --address "OpenLab Augsburg, Elisenstraße 1, 86159 Augsburg, Germany" \
  --start-date "2021-07-31T14:23+02:00" \
  --end-date "2021-07-31T23:42+02:00" \
  --type 9 \
  --default-check-in-length-in-minutes 300 \
  --filepath sommerfest-cwa-qr.svg
