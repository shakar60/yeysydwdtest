local SavingSystem = 
loadstring(game:HttpGet("https://raw.githubusercontent.com/Grayy12/SavingSys-Alpha/main/src.lua", true))() 

local OrionLib = loadstring(game:HttpGet("https://raw.githubusercontent.com/shlexware/Orion/main/source"))() 
local Player = game.Players.LocalPlayer 
local Window = 
OrionLib:MakeWindow({ Name = "Key System", HidePremium = false, SaveConfig = true, IntroEnabled = false }) 

local File = SavingSystem.Init("ExampleFolder", "ExampleFile.txt") 
local Keysys = File:SetupKey("ExampleKey") 

OrionLib:MakeNotification({ 
Name = "Logged in!", 
Content = "You are logged in as " .. Player.Name .. ".", 
Image = "rbxassetid://4483345998", 
Time = 5, 
}) 

_G.KeyInput = "string" 

function MakeScriptHub() 
print("EnteredCorrectKey") 
end 

function CorrectKeyNotification() 
OrionLib:MakeNotification({ 
Name = "Correct Key!", 
Content = "You have entered the correct key ", 
Image = "rbxassetid://4483345998", 
Time = 5, 
}) 
end 

function IncorrectKeyNotification() 
OrionLib:MakeNotification({ 
Name = "Incorrect Key!", 
Content = "You have entered the incorrect key ", 
Image = "rbxassetid://4483345998", 
Time = 5, 
}) 
end 

local Tab = Window:MakeTab({ 
Name = "Key", 
Icon = "rbxassetid://4483345998", 
PremiumOnly = false, 
}) 

Tab:AddTextbox({ 
Name = "Enter Key", 
Default = "", 
TextDisappear = true, 
Callback = function(Value) 
_G.KeyInput = Value 
end, 
}) 

Tab:AddButton({ 
Name = "Check Key!", 
Callback = function() 
if Keysys:CheckKey(_G.KeyInput) then 
MakeScriptHub() 
CorrectKeyNotification() 
else 
IncorrectKeyNotification() 
end 
end, 
}) 
