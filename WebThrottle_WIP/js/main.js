$(function(){

    $("#menu-toggle").click(function(e) {
        e.preventDefault();
        $("#wrapper").toggleClass("toggled");
    });

    slider = null;
    $("#slider").roundSlider({
        sliderType: "min-range",
        handleShape: "dot",
        lineCap: "round",
        radius: 111,
        value: 0,
        circleShape: "pie",
        startAngle: 315,
        handleSize: "+16",
        width: 12,
        mouseScrollAction: true,
        create: function(){
            slider = $("#slider").data("roundSlider");
        },
        valueChange: function(){
            console.log("Triggered Value..");
            console.log(slider.getValue());
        }
    });
    
    


    
});
