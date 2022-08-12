function start(page){
    clearData();
    getData(function(data){
        // console.log(JSON.parse(data));
        let js_data;
        try {
            js_data = JSON.parse(data);
        } catch (err) {
            console.log('Unable to parse json')
        }
        appendData(js_data.data);
    }, page);
}

function clearData(){
    let container = document.querySelector('#main_part');
    container.innerHTML = '';
}

function getData(callback, page){
    let container = document.querySelector('#main_container');
    let XML = new XMLHttpRequest();
    if (page == 2) {
        XML.open('get', 'https://reqres.in/api/users?page=2');    
    }
    else{
        XML.open('get', 'https://reqres.in/api/users?page=1');
    }
    XML.send();

    XML.onload = function(){
        try {
            let json = XML.responseText;
            callback(json);
        } catch (err) {
            console.log("fail to get JSON data")
        }
    }
}
/**
 * <article class="card">
        <header>
            <h2>A short heading</h2>
        </header>    
        <img src="balloons.jpg" alt="Hot air balloons">
        <div class="content">
            <p> The idea of reaching the North Pole by means of balloons appears to have been entertained many years ago. </p>
        </div>
            
    </article>
 */

function appendData(data){
    let container = document.querySelector('#main_part');
    data.forEach(element => {
        container.appendChild(CreateCard(element));
    });
}

function CreateCard(data){
    let article = document.createElement('article');
    article.className = 'card';
    let header = document.createElement('header');
    let h2 = document.createElement('h2');
    h2.innerHTML = `${data.first_name} ${data.last_name}`;
    header.appendChild(h2);
    article.appendChild(header);

    let img = document.createElement('img');
    img.src = data.avatar;
    img.alt = "Profile pic";

    article.appendChild(img);

    let div = document.createElement('div');
    div.classList = 'content';
    let p = document.createElement('p');
    p.innerHTML = '<b>Email:</b>' + data.email;
    div.appendChild(p);

    article.appendChild(div);
    return article;
}