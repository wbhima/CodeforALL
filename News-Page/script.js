const Fetch_data = async() => {

  let query = document.querySelector("#query").value;

  let api_key = "jtNlZAGUrre09G4omeQ0IS4PyUMEull0";

  try {

    let response = await fetch("https://api.nytimes.com/svc/search/v2/articlesearch.json?q="+`${query}`+"&api-key="+`${api_key}`);

    let data = await response.json();

    display_res(data);

    console.log(data);

    console.log(`Success`);

  }catch(err) {

    console.log(`Not found or network issue`);

  }

}

const display_res = data => {

  document.querySelector("#image_1").src = "https://static01.nyt.com/"+data.response.docs[0].multimedia[0].url;

  document.querySelector("#info_1").textContent = data.response.docs[0].abstract;

  document.querySelector("#header_1").textContent = data.response.docs[0].headline.main;

  document.querySelector("#main_1").textContent = data.response.docs[0].lead_paragraph;

  document.querySelector("#more_1").href = data.response.docs[0].web_url;

  document.querySelector("#more_1").innerHTML = `See more`;

  document.querySelector("#image_2").src = "https://static01.nyt.com/"+data.response.docs[1].multimedia[0].url;

  document.querySelector("#info_2").textContent = data.response.docs[1].abstract;

  document.querySelector("#header_2").textContent = data.response.docs[1].headline.main;

  document.querySelector("#main_2").textContent = data.response.docs[1].lead_paragraph;

  document.querySelector("#more_2").href = data.response.docs[1].web_url;

  document.querySelector("#more_2").innerHTML = `See more`;

  document.querySelector("#image_3").src = "https://static01.nyt.com/"+data.response.docs[2].multimedia[0].url;

  document.querySelector("#info_3").textContent = data.response.docs[2].abstract;

  document.querySelector("#header_3").textContent = data.response.docs[2].headline.main;

  document.querySelector("#main_3").textContent = data.response.docs[2].lead_paragraph;

  document.querySelector("#more_3").href = data.response.docs[2].web_url;

  document.querySelector("#more_3").innerHTML = `See more`;

  document.querySelector("#image_4").src = "https://static01.nyt.com/"+data.response.docs[3].multimedia[0].url;

  document.querySelector("#info_4").textContent = data.response.docs[3].abstract;

  document.querySelector("#header_4").textContent = data.response.docs[3].headline.main;

  document.querySelector("#main_4").textContent = data.response.docs[3].lead_paragraph;

  document.querySelector("#more_4").href = data.response.docs[3].web_url;

  document.querySelector("#more_4").innerHTML = `See more`;

  document.querySelector("#image_5").src = "https://static01.nyt.com/"+data.response.docs[4].multimedia[0].url;

  document.querySelector("#info_5").textContent = data.response.docs[4].abstract;

  document.querySelector("#header_5").textContent = data.response.docs[4].headline.main;

  document.querySelector("#main_5").textContent = data.response.docs[4].lead_paragraph;

  document.querySelector("#more_5").href = data.response.docs[4].web_url;

  document.querySelector("#more_5").innerHTML = `See more`;

  document.querySelector("#image_6").src = "https://static01.nyt.com/"+data.response.docs[5].multimedia[0].url;

  document.querySelector("#info_6").textContent = data.response.docs[5].abstract;

  document.querySelector("#header_6").textContent = data.response.docs[5].headline.main;

  document.querySelector("#main_6").textContent = data.response.docs[5].lead_paragraph;

  document.querySelector("#more_6").href = data.response.docs[5].web_url;

  document.querySelector("#more_6").innerHTML = `See more`;

  document.querySelector("#image_7").src = "https://static01.nyt.com/"+data.response.docs[6].multimedia[0].url;

  document.querySelector("#info_7").textContent = data.response.docs[6].abstract;

  document.querySelector("#header_7").textContent = data.response.docs[6].headline.main;

  document.querySelector("#main_7").textContent = data.response.docs[6].lead_paragraph;

  document.querySelector("#more_7").href = data.response.docs[6].web_url;

  document.querySelector("#more_7").innerHTML = `See more`;

  document.querySelector("#image_8").src = "https://static01.nyt.com/"+data.response.docs[7].multimedia[0].url;

  document.querySelector("#info_8").textContent = data.response.docs[7].abstract;

  document.querySelector("#header_8").textContent = data.response.docs[7].headline.main;

  document.querySelector("#main_8").textContent = data.response.docs[7].lead_paragraph;

  document.querySelector("#more_8").href = data.response.docs[7].web_url;

  document.querySelector("#more_8").innerHTML = `See more`;

}

onload = Fetch_data();
