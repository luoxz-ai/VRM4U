
Remove-Item -Recurse ./_out/Intermediate
Remove-Item -Recurse ./_out/Binaries/Win64/*.pdb

Move-Item -Path ./_out -Destination ./Plugins

Compress-Archive -Force -Path ./Plugins -DestinationPath $Args[0]


Move-Item -Path ./Plugins -Destination ./_out

