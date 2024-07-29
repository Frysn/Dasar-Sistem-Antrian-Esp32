const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Antrian</title>
    <script>
        let numerawal = 0
        let numer = 0
        setInterval(() => {
            fetch('/data')
                .then(response => response.json())
                .then(data => {
                    numerawal = data.antrian
                    if (JSON.stringify(numerawal) !== JSON.stringify(numer)){
                        numer = numerawal
                        update()
                    }
                });
        }, 100);


        document.getElementById('antrian').innerHTML = numer

        function update(){
            document.getElementById('antrian').innerHTML = numer
            spek(numer)
        }

        function nextCustomer(){
            numer++
            update()
        }

        function prevCustomer(){
            update()
        }

        function spek(numer){
            const msg = new SpeechSynthesisUtterance;
            msg.text = "Nomor antrian " + numer + "Silahkan Menuju Ke loket";
            msg.lang = 'id-ID';
            msg.rate = 0.9
            msg.pitch = 1
            window.speechSynthesis.cancel();
            window.speechSynthesis.speak(msg)
        }
    </script>
</head>
<body>
    <h1>Antrian</h1>
    <h1 id="antrian">
        <!-- Antrian diisi disini -->
    </h1>
    <button onclick="prevCustomer()">Ulang</button>
</body>
</html>

)rawliteral";