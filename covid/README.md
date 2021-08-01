# Covid Infomaterial

Einige Skripte und Templates für Veranstaltungen & Covidmaßnamen.

./generate-qr-code-for.sh nimmt einen Output-Dateinamen und einen beliebigen Text (z.B. einen Link) und enkodiert den Text in einen QR-Code.

./sommerfest-generate-qr-code.sh lädt das `cwa-event-qr-code` CLI tool von der Corona Warn App herunter und generiert einen Event-QR-Code für unser Sommerfest, mit dem man sich einchecken kann. Wir können das für andere Events entsprechend abändern und in Plakate einbinden.

./sommerfest-covid-infos.odt ist das Plakat, das wir auf dem Sommerfest benutzt haben. Es enthält einen großen QR code für die CWA app (generiert mit dem Skript) und zwei kleine mit den Links auf die CWA app downloads (fdroid und iOS store).

./shell.nix ist eine `nix-shell`, um die nötigen Tools (`nodejs` und `qrencode`) für die Skripte zu installieren.
