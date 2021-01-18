## CS3307 - Stage 3 Group 16

## Preparing to Build:

cd downloads    
sudo bash installp1.sh      

## Building and Running:

cd source_code   
qmake     
make      
./3307test   


## Acceptance Tests:
Interacting with the Pi and uploading images:
* Test button opens file directory - PASS
* Test with png and jpeg files - PASS
* Test with any other file type (pdf) - FAIL

Handwriting recognized and stored as a string:
* Test writing on lined paper - PASS
* Test writing on blank paper - PASS
* Test messy writing - FAIL
* Test black pen - PASS
* Test brightly coloured pen - PASS
* Test highlighted words - PASS
* Test using a pdf - FAIL

Writing can be translated to different languages:
* Test user can select which language - PASS
* Test translation to French - PASS
* Test translation to Spanish - PASS
* Test strings with punctuation - PASS

Converting to .txt file:
* Test that the .txt file exists in the directory and can be opened - PASS
* Test that the contents of the .txt file match the expected contents - PASS

Converting .docx file:
* Test that the .docx file exists and can be opened/edited - PASS
* Test that the contents of the .docx file match the expected contents - PASS

Converting to .wav file:
* Test that the .wav file exists in the directory and can be opened - PASS
* Test that the played sound can be heard - PASS
* Test that the audio matches the shown text box - PASS


Project by Group 16: Bennett McDonald, Connor Ciavarella, Hanna Dodd, Maximilian Smosarski, Jerrie Berrafati
