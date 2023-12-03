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

// Converts total time to minutes
function timeSum(hourTime, minuteTime)
{
    return ((parseInt(hourTime) * 60) + parseInt(minuteTime));
}

function Kroger_ProcessRecipeBlockElement(RecipeBlock)
{
    // RB Index 3 is total time, Child Index 1 is actual time text
    return Kroger_ProcessTimeElement(RecipeBlock[3].childNodes[1].textContent);
}

function Kroger_ProcessTimeElement(timeElementText)
{
    const timeElementSegments = timeElementText.split(" ");

    if (timeElementText.includes("hour") && timeElementText.includes("minute")) // Compound hours and minutes
    {
        return timeSum(timeElementSegments[0], timeElementSegments[2]);
    }
    else if (timeElementText.includes("hour")) // A number of hours with no minutes
    {
        return timeSum(timeElementSegments[0], 0);
    }
    else if (timeElementText.includes("minute")) // A number of minutes less than an hour
    {
        return timeSum(0, timeElementSegments[0]);
    }
    else
    {
        return 60; // default to an hour if something breaks
    }
}

// Pulls the time in hours from the Skinny Foods website
function ST_GetHourTimeFromDocument()
{
    try { // Try to get the time in hours from named element
        return document.querySelectorAll("span.wprm-recipe-details.wprm-recipe-details-hours.wprm-recipe-total_time.wprm-recipe-total_time-hours")[0].textContent;
    }
    catch { // if it fails, set to zero
        return "0";
    }
}

// Pulls the time in minutes from the Skinny Foods website
function ST_GetMinuteTimeFromDocument()
{
    try { // Try to get the time in minutes from named element
        return document.querySelectorAll("span.wprm-recipe-details.wprm-recipe-details-minutes.wprm-recipe-total_time.wprm-recipe-total_time-minutes")[0].textContent;
    }
    catch { // if it fails, set to zero
        return "0";
    }
}

var windowURL = window.location.href;
var totalTime;

if (determineCurrentSite(windowURL) == "Kroger") // Kroger Website Logic
{
    totalTime = Kroger_ProcessRecipeBlockElement(document.querySelectorAll("span.RecipeLabeledValue.block"));
}
else if (determineCurrentSite(windowURL) == "ST") // SkinnyTaste Website logic
{
    totalTime = timeSum(ST_GetHourTimeFromDocument(), ST_GetMinuteTimeFromDocument());
}
else // Default to one hour if something goes wrong
{
    totalTime = 60;
}

completion(totalTime);
