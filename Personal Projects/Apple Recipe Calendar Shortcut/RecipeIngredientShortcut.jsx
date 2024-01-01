// Checks URL to see what site we're on
function determineCurrentSite(url)
{
    if (url.includes("kroger.com"))
    {
        return "Kroger";
    }
    else if (url.includes("skinnytaste.com"))
    {
        return "ST";
    }
    else
    {
        return "";
    }
}

// This returns the list of ingredients (For Kroger)
function Kroger_getIngredientList()
{
    // Access the 2nd child as the first is just the word "Ingredients"
    return document.querySelectorAll("section.RecipeDetail-ingredients")[0].children[1];
}

// This returns the length of the list of ingredients
function Kroger_getIngredientListLength()
{
    // Pull the length by getting the number of ingredients in the ul
    return document.querySelectorAll("section.RecipeDetail-ingredients")[0].children[1].childNodes.length;
}

// Dump all of the ingredients into a string separated by newlines
function Kroger_getIngredientText()
{
    var recipeIngredientOutputList = "";

    for (var i = 0; i < Kroger_getIngredientListLength(); i++)
    {
        recipeIngredientOutputList += Kroger_getIngredientList().children[i].textContent;
        recipeIngredientOutputList += "\n";
    }

    return recipeIngredientOutputList;
}

// This returns the list of ingredients (For SkinnyTaste)
function ST_getIngredientList()
{
    return document.querySelectorAll("ul.wprm-recipe-ingredients")[0];
}

function ST_getIngredientListLength()
{
    // Pull the length by getting the number of li (ingredients) in the ul (list of ingredients)
    return document.querySelectorAll("ul.wprm-recipe-ingredients")[0].childNodes.length;
}

function ST_getIngredientNameLength(ingredientIndex)
{
    // Pull the length by getting the number of spans (words) in the li (ingredients)
    return document.querySelectorAll("ul.wprm-recipe-ingredients")[0].childNodes[ingredientIndex].childNodes.length;
}

// Dump all of the ingredients into a string separated by newlines
function ST_getIngredientText()
{
    var recipeIngredientOutputList = "";

    for (var i = 0; i < ST_getIngredientListLength(); i++)
    {
        // Read how many children are in the ingredient block, since every word is a different child (for some reason)
        for (var j = 1; j < ST_getIngredientNameLength(i); j++)
        {
            // This gets the li elements with the broken up text
            recipeIngredientOutputList += ST_getIngredientList().childNodes[i].childNodes[j].textContent;
        }
        recipeIngredientOutputList += "\n";
    }

    return recipeIngredientOutputList;
}

var windowURL = window.location.href;
var recipeIngredientList;

if (determineCurrentSite(windowURL) == "Kroger") // Kroger Website Logic
{
    recipeIngredientList = Kroger_getIngredientText();
}
else if (determineCurrentSite(windowURL) == "ST") // SkinnyTaste Website logic
{
    recipeIngredientList = ST_getIngredientText();
}
else // Default to N/A if something goes wrong
{
    recipeIngredientList = "N/A";
}

completion(recipeIngredientList);