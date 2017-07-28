var express = require('express');
var app = express();
app.use(express.static('public'));

app.get('/', function (req, res) {
    res.send("hola hola");
});

app.get('/getFile', function (req, res) {
   res.sendFile( __dirname + "/" + "my_file.txt" );
})

app.get('/index.htm', function (req, res) {
   res.sendFile( __dirname + "/" + "ColorPicker.html" );
})

app.get('/getValues', function (req, res) { 

    var fs = require('fs');
    var stream = fs.createWriteStream("my_file.txt");
    stream.once('open', function(fd) {
       stream.write(req.query.red + "\n");
       stream.write(req.query.green + "\n");
       stream.write(req.query.blue + "\n");
       stream.end();
    });

    res.send("listo");
});

var server = app.listen(8081, function () {
   var host = server.address().address
   var port = server.address().port
   
   console.log("Example app listening at http://%s:%s", host, port)
})
