function submitToAPI(e) {
	e.preventDefault();
	var URL = "https://k39h4715i6.execute-api.eu-west-1.amazonaws.com/prod";

		if ($("#objet-input").val()=="") {
			alert ("Veuillez entrer un Objet");
			return;
		}

		 if ($("#email-input").val()=="") {
			 alert ("Veuillez entrer votre mail");
			 return;
		 }

		 var reeamil = /^([\w-\.]+@([\w-]+\.)+[\w-]{2,6})?$/;
		 if (!reeamil.test($("#email-input").val())) {
			 alert ("Veuillez entrer un e-mail valid");
			 return;
		 }

	var objet = $("#objet-input").val();
	var email = $("#email-input").val();
	var desc = $("#description-input").val();
	var data = {
	   objet : objet,
	   email : email,
	   message : desc
	 };

	$.ajax({
	  type: "POST",
	  url : "https://k39h4715i6.execute-api.eu-west-1.amazonaws.com/prod",
	  dataType: "json",
	  crossDomain: "true",
	  contentType: "application/json; charset=utf-8",
	  data: JSON.stringify(data),

	  
	  success: function () {
		// clear form and show a success message
		alert("Succès");
		document.getElementById("contact-form").reset();
		location.reload();
	  },
	  error: function () {
		// show an error message
		alert("Echec");
	  }});
  }