# UE5 基于UnLua的扩展

用法:复制Plugins下的文件夹到项目的Plugins目录下。

QQ交流群: 688204277

## UELuaPb

开源项目[lua-protobuf](https://github.com/starwing/lua-protobuf)的UnLua的封装。

Lua用法:

```
local pb = require "pb"
pb.load(pbdata)

local data = pb.encode("Game.Game", pbtab)
local pbtab = pb.decode("Game.Game", data)
```

## UELuaMore

UnLua的绑定只有核心部分，项目需要自行绑定一些扩展功能。

FBase64绑定

```
local rtnData = ""
local isSuccess = UE.FBase64.Decode(base64Str, rtnData)
```