using System.Runtime.InteropServices;
using System.Text.Json;
using System.Text.Json.Nodes;
using System.Text.Json.Serialization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Filters;
using Newtonsoft;
using Newtonsoft.Json;

var builder = WebApplication.CreateBuilder(args);
builder.WebHost.UseUrls("http://127.0.0.1:3000");
var app = builder.Build();

app.MapGet("/", () => "The Will of the City Calls");
app.MapGet("/api", () => "API");
// app.MapGet("/login", () => "LOGIN");
// app.MapGet("/log", () => "LOG");
app.MapGet("/iap", () => "IAP");
app.MapGet("/privacy", () => "PRIVACY");
app.MapGet("/admin", () => "ADMIN");




string CANNED_SERVERINFOS = """
[
  {
    "platform": "android",
    "serviceType": "product",
    "serverId": "aos_product",
    "versions": ["1.112.0"],
    "serverUrl": "https://www.limbuscompanyapi.com",
    "logServerUrl": "https://battlelog.limbuscompanyapi.com",
    "presenceServerUrl": "https://presence.limbuscompanyapi.com",
    "noticeUrl": "https://notice.limbuscompanyapi.com",
    "cdnUrl": "",
    "guestAuthErrors": [101,15003,40004,40005],
    "enablePacketCrypt": true,
    "enableLogPacketCrypt": true,
    "enableAgreementVersionCheck": true,
    "enableNetworkingUIProcessPurchase": true,
    "enableCheckUpdateCatalogSteamFixed": true,
    "enableCheckUpdateCatalogToTitle": false,
    "enableCheckUpdateTextAsset": true,
    "enableCheckError": true,
    "enableBLogSync": true
  },
  {
    "platform": "ios",
    "serviceType": "product",
    "serverId": "ios_product",
    "versions": ["1.112.0"],
    "serverUrl": "https://www.limbuscompanyapi.com",
    "logServerUrl": "https://battlelog.limbuscompanyapi.com",
    "presenceServerUrl": "https://presence.limbuscompanyapi.com",
    "noticeUrl": "https://notice.limbuscompanyapi.com",
    "cdnUrl": "",
    "guestAuthErrors": [101,15003,40004,40005],
    "enablePacketCrypt": true,
    "enableLogPacketCrypt": true,
    "enableAgreementVersionCheck": true,
    "enableNetworkingUIProcessPurchase": true,
    "enableCheckUpdateCatalogSteamFixed": true,
    "enableCheckUpdateCatalogToTitle": false,
    "enableCheckUpdateTextAsset": true,
    "enableBLogSync": true
  },
  {
    "platform": "windows",
    "serviceType": "product",
    "serverId": "win_product",
    "versions": ["1.112.0"],
    "serverUrl": "https://www.limbuscompanyapi.com",
    "logServerUrl": "https://battlelog.limbuscompanyapi.com",
    "presenceServerUrl": "https://presence.limbuscompanyapi.com",
    "noticeUrl": "https://notice.limbuscompanyapi.com",
    "cdnUrl": "",
    "guestAuthErrors": [101,15003,40004,40005],
    "enablePacketCrypt": true,
    "enableLogPacketCrypt": true,
    "enableAgreementVersionCheck": true,
    "enableNetworkingUIProcessPurchase": true,
    "enableCheckUpdateCatalogSteamFixed": true,
    "enableCheckUpdateCatalogToTitle": false,
    "enableCheckUpdateTextAsset": true,
    "enableCheckError": true,
    "enableBLogSync": true
  },
  {
    "platform": "android",
    "serviceType": "exam",
    "serverId": "aos_exam",
    "versions": ["1.112.0"],
    "serverUrl": "https://www.limbuscompanyapi-2.com",
    "logServerUrl": "https://battlelog.limbuscompanyapi-2.com",
    "noticeUrl": "https://notice.limbuscompanyapi-2.com",
    "cdnUrl": "",
    "guestAuthErrors": [101,15003,40004,40005],
    "enablePacketCrypt": true,
    "enableLogPacketCrypt": true,
    "enableAgreementVersionCheck": true,
    "enableNetworkingUIProcessPurchase": true,
    "enableCheckUpdateCatalogSteamFixed": true,
    "enableCheckUpdateCatalogToTitle": false,
    "enableCheckUpdateTextAsset": true,
    "enableCheckError": true,
    "enableBLogSync": true
  },
  {
    "platform": "ios",
    "serviceType": "exam",
    "serverId": "ios_exam",
    "versions": ["1.112.0"],
    "serverUrl": "https://www.limbuscompanyapi-2.com",
    "logServerUrl": "https://battlelog.limbuscompanyapi-2.com",
    "noticeUrl": "https://notice.limbuscompanyapi-2.com",
    "cdnUrl": "",
    "guestAuthErrors": [101,15003,40004,40005],
    "enablePacketCrypt": true,
    "enableLogPacketCrypt": true,
    "enableAgreementVersionCheck": true,
    "enableNetworkingUIProcessPurchase": true,
    "enableCheckUpdateCatalogSteamFixed": true,
    "enableCheckUpdateCatalogToTitle": false,
    "enableCheckUpdateTextAsset": true,
    "enableBLogSync": true
  },
  {
    "platform": "windows",
    "serviceType": "exam",
    "serverId": "win_exam",
    "versions": ["1.116.2"],
    "serverUrl": "https://www.limbuscompanyapi-2.com",
    "logServerUrl": "https://battlelog.limbuscompanyapi-2.com",
    "noticeUrl": "https://notice.limbuscompanyapi-2.com",
    "cdnUrl": "",
    "guestAuthErrors": [101,15003,40004,40005],
    "enablePacketCrypt": true,
    "enableLogPacketCrypt": true,
    "enableAgreementVersionCheck": true,
    "enableNetworkingUIProcessPurchase": true,
    "enableCheckUpdateCatalogSteamFixed": true,
    "enableCheckUpdateCatalogToTitle": false,
    "enableCheckUpdateTextAsset": true,
    "enableCheckError": true,
    "enableBLogSync": true
  }
]
""";

async void basicEndpointTest(HttpRequest request)
{
    using var reader = new StreamReader(request.Body);
    
    var body = await reader.ReadToEndAsync();
    File.WriteAllText("test.log", body);
    File.WriteAllText("test.log", "\n");
    Console.WriteLine(body);
}

// POSTPONED TO TOMORROW BECAUSE DAMMIT I WANNA SLOP



async Task<ResponsePacket> ParseRequestPacket<T1, T2>(HttpRequest request) where T1 : reqPacketBase, new() where T2 : resPacketBase
{
    RequestPacket req = await RequestPacket.CreateAsync<T1>(request);
    ResponsePacket res = ResponsePacket.Create<T2>(req);
    return res;
}

async Task<IResult> ProcessRequestIntoResult<T1, T2>(HttpRequest request) where T1 : reqPacketBase, new() where T2 : resPacketBase
{
    RequestPacket req = await RequestPacket.CreateAsync<T1>(request);
    ResponsePacket res = ResponsePacket.Create<T2>(req);
    return Results.Content(JsonConvert.SerializeObject(res), statusCode: 200);
}



// var data = JsonSerializer.Deserialize<Dictionary<string, JsonElement>>(CANNED_SERVERINFOS);
// Convert it back to JSON without unnecessary whitespace (They don't know this is actually good code)
JsonDocument? doc = System.Text.Json.JsonSerializer.Deserialize<JsonDocument>(CANNED_SERVERINFOS);
string minifiedJson = System.Text.Json.JsonSerializer.Serialize(doc);

// becuase this just exists for some reason! I love this. 
app.MapGet("/serverinfos.json", async (HttpRequest request) =>
{
    basicEndpointTest(request);
    return Results.Content(minifiedJson, statusCode:200);
});

// ------------- LOGIN ROUTES ---------------

var loginGroup = app.MapGroup("/login");

loginGroup.MapPost("/CheckClientVersion", async (HttpRequest request) =>
{
    // RequestPacket req = await RequestPacket.CreateAsync<reqCheckClientVersion>(request);
    // ResponsePacket res = ResponsePacket.Create<resCheckClientVersion>(req);
    // return Results.Content(JsonConvert.SerializeObject(res), statusCode: 200);
    return await ProcessRequestIntoResult<reqCheckClientVersion, resCheckClientVersion>(request);
});

loginGroup.MapPost("/GetTermsOfUseStateAll", async (HttpRequest request) =>
{
    // RequestPacket req = await RequestPacket.CreateAsync<reqGetTermsOfUseStateAll>(request);
    // ResponsePacket res = ResponsePacket.Create<resGetTermsOfUseStateAll>(req);
    // return Results.Content(JsonConvert.SerializeObject(res), statusCode: 200);
    return await ProcessRequestIntoResult<reqGetTermsOfUseStateAll, resGetTermsOfUseStateAll>(request);
});

loginGroup.MapPost("/UpdateTermsOfUseState", async (HttpRequest request) =>
{
    // RequestPacket req = await RequestPacket.CreateAsync<reqUpdateTermsOfUseState>(request);
    // ResponsePacket res = ResponsePacket.Create<resUpdateTermsOfUseState>(req);
    // return Results.Content(JsonConvert.SerializeObject(res), statusCode: 200);
    return await ProcessRequestIntoResult<reqUpdateTermsOfUseState, resUpdateTermsOfUseState>(request);
});

loginGroup.MapPost("/SignInAsSteam", async (HttpRequest request) =>
{
    // RequestPacket req = await RequestPacket.CreateAsync<reqSignInAsSteam>(request);
    // ResponsePacket res = ResponsePacket.Create<resSignInAsSteam>(req);
    // return Results.Content(JsonConvert.SerializeObject(res), statusCode: 200);
    return await ProcessRequestIntoResult<reqSignInAsSteam, resSignInAsSteam>(request);
});


// ------------- API ROUTES --------------- (Alphabetical Order)
var apiGroup = app.MapGroup("/api");
// apiGroup.MapPost("/ClaimClosedGachaRewards", async (HttpRequest request) =>
// {
//     reqClaimClosedGachaRewards req = await reqPacketBase.CreateAsync<reqClaimClosedGachaRewards>(request);
//     resClaimClosedGachaRewards res = new resClaimClosedGachaRewards(req);
//     return Results.Content(JsonSerializer.Serialize(res), statusCode: 200);
// });

apiGroup.MapPost("/ExitStory", async (HttpRequest request) =>
{
    // RequestPacket req = await RequestPacket.CreateAsync<reqExitStory>(request);
    // ResponsePacket res = ResponsePacket.Create<resExitStory>(req);
    // return Results.Content(JsonConvert.SerializeObject(res), statusCode: 200);
    return await ProcessRequestIntoResult<reqExitStory, resExitStory>(request);
});

apiGroup.MapPost("/FetchLatestSynchronousData", async (HttpRequest request) =>
{
    // RequestPacket req = await RequestPacket.CreateAsync<reqFetchLatestSynchronousData>(request);
    // ResponsePacket res = ResponsePacket.Create<resFetchLatestSynchronousData>(req);
    // return Results.Content(JsonConvert.SerializeObject(res), statusCode: 200);
    return await ProcessRequestIntoResult<reqFetchLatestSynchronousData, resFetchLatestSynchronousData>(request);
});

apiGroup.MapPost("/LoadUserDataAll", async (HttpRequest request) =>
{
    // RequestPacket req = await RequestPacket.CreateAsync<reqLoadUserDataAll>(request);
    // ResponsePacket res = ResponsePacket.Create<resLoadUserDataAll>(req);
    // return Results.Content(JsonConvert.SerializeObject(res), statusCode: 200);
    return await ProcessRequestIntoResult<reqLoadUserDataAll, resLoadUserDataAll>(request);
});

// apiGroup.MapPost("/GetDungeonSaveInfoAll", async (HttpRequest request) =>
// {
//     reqGetDungeonSaveInfoAll req = await reqPacketBase.CreateAsync<reqGetDungeonSaveInfoAll>(request);
//     resGetDungeonSaveInfoAll res = new resGetDungeonSaveInfoAll(req);
//     return Results.Content(JsonSerializer.Serialize(res), statusCode: 200);
// });

// apiGroup.MapPost("/GetRailwayDungeonNodeAndLogAll", async (HttpRequest request) =>
// {
//     reqGetRailwayDungeonNodeAndLogAll req = await reqPacketBase.CreateAsync<reqGetRailwayDungeonNodeAndLogAll>(request);
//     resGetRailwayDungeonNodeAndLogAll res = new resGetRailwayDungeonNodeAndLogAll(req);
//     return Results.Content(JsonSerializer.Serialize(res), statusCode: 200);
// });

apiGroup.MapPost("/PlayGacha", async (HttpRequest request) =>
{
    // RequestPacket req = await RequestPacket.CreateAsync<reqPlayGacha>(request);
    // ResponsePacket res = ResponsePacket.Create<resPlayGacha>(req);
    // return Results.Content(JsonConvert.SerializeObject(res), statusCode: 200);
    return await ProcessRequestIntoResult<reqPlayGacha, resPlayGacha>(request);
});


// fallback in case everything is DEAD!
app.MapPost("{*path}", async (HttpRequest request, string path) =>
{
    Console.Write($"({path}) = "); // if it's a fallback, we should see what it is
    // RequestPacket req = await RequestPacket.CreateAsync<reqPacketBase>(request);
    // ResponsePacket res = ResponsePacket.Create<resPacketBase>(req);
    // return Results.Content(JsonConvert.SerializeObject(res), statusCode: 200);
    return await ProcessRequestIntoResult<reqPacketBase, resPacketBase>(request);
});

app.Run();