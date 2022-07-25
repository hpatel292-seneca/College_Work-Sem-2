var filterType = ""; // sets the filter type to "" (will later be dog, cat or bird)
var filterAgeMin = 0; // sets the filter age min to 0 (for no minimum age filter)
var filterAgeMax = Number.MAX_VALUE; // sets the filter age max to the largest number possible (for no maximum age filter)
function loadTableWithFilters(){
    let tbody = document.querySelector("#main-table-body");
    tbody.innerHTML = "";
    for (let i = 0; i < petData.length; i++) {
        if ((filterType === petData[i].type  || filterType === "" )&&(petData[i].age >= filterAgeMin && petData[i].age < filterAgeMax) )
        {
            let trElement = document.createElement('tr');
            let td1 = document.createElement('td');
            let imgElement = document.createElement('img');

            imgElement.src = petData[i].image.src;
            imgElement.alt = petData[i].image.alt;
            imgElement.height = petData[i].image.height;
            imgElement.width = petData[i].image.width;
            switch (petData[i].type) {
                case "dog":
                    imgElement.onclick = filterDog;
                    break;
                case "cat":
                    imgElement.onclick = filterCat;
                    break;
                case "bird":
                    imgElement.onclick = filterBird;
                    break;     
            }
            td1.appendChild(imgElement);
            let td2 = document.createElement('td');
            td2.classList.add("Table-content")
            let hL4 = document.createElement('h4');
            let tnode = document.createTextNode(petData[i].name);
            hL4.appendChild(tnode);
            td2.appendChild(hL4);
            let pElement = document.createElement('p');
            pElement.innerHTML = petData[i].description;
            td2.appendChild(pElement);
            let spanELe = document.createElement('span');
            spanELe.append("Age: " + petData[i].age + "years old");
            td2.appendChild(spanELe);
            trElement.appendChild(td1);
            trElement.appendChild(td2);
            tbody.append(trElement);
        }
    }
};
function filterDog(){
    filterType = "dog";
    loadTableWithFilters();
}

function filterCat(){
    filterType = "cat";
    loadTableWithFilters();
}

function filterBird(){
    filterType = "bird";
    loadTableWithFilters();
}

function filter_zero_1(){
    filterAgeMin = 0;
    filterAgeMax = 1;
    loadTableWithFilters();
}

function filter_1_3(){
    filterAgeMin = 1;
    filterAgeMax = 3;
    loadTableWithFilters();
}

function filter_4_plus(){
    filterAgeMin = 4;
    filterAgeMax = Number.MAX_VALUE;
    loadTableWithFilters();
}

function filterAllPets(){
    filterType = "";
    filterAgeMin = 0;
    filterAgeMax = Number.MAX_VALUE;
    loadTableWithFilters();
}
window.onload = loadTableWithFilters;