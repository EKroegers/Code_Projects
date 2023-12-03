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

var windowURL = window.location.href;
var recipeTitle;

if (determineCurrentSite(windowURL) == "Kroger") // Kroger Website Logic
{
    recipeTitle = document.querySelectorAll("h1.kds-Heading.kds-Heading--xl.RecipeDetail-title.max-w-full.mt-16.mb-16.font-normal")[0].textContent;
}
else if (determineCurrentSite(windowURL) == "ST") // SkinnyTaste Website logic
{
    recipeTitle = document.querySelectorAll("h1.entry-title")[0].textContent;
}
else // Default to N/A if something goes wrong
{
    recipeTitle = "N/A";
}

completion(recipeTitle);
