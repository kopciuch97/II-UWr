function initMap()   
{   
    var coords = new google.maps.LatLng(53.41935400090768,14.58160400390625);
    var mapOptions = {
      zoom: 10,
      center: coords,
      mapTypeId: google.maps.MapTypeId.ROADMAP
    };
    var map = new google.maps.Map(document.getElementById("map"), mapOptions); 
    
    var markerOptions =  
    {  
        position: new google.maps.LatLng(53.400,14.600),  
        map: map,
        draggable: true,
        title: "Przesuwalny marker"  
    }  
    var marker = new google.maps.Marker(markerOptions);
    
    var infoWindow = new google.maps.InfoWindow();
    infoWindow.setContent('<strong>TITLE</strong><br />Tekst z informacją dla markera<br /><a href="http://www.onet.pl/">ONET</a>');
    infoWindow.open(map, marker);
    infoWindow.backgroundColor = 'red';

    google.maps.event.addListener( marker, 'click', function(e) {
        infoWindow.open(map,marker);
    });		
}   