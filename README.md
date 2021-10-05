# 開發紀錄 
## 課程名稱
2021 Fall - 數位音樂訊號分析 Analysis of Digital Music Signal

## 本周目標(week3)
1. JUCE Framework 開發環境設定
2. 製作簡單 Plug-in，並將 Sine Wave Synthesizer 改成方波、三角波、鋸齒波



## JUCE 環境設定

### 安裝 JUCE
![](https://i.imgur.com/NrY6NyN.png)

### 設定 JUCE 路徑
執行 Projucer -> File -> Global Path ->  
![](https://i.imgur.com/JKFAbJz.png)


### 創建 Audio/MIDI plug-in
![](https://i.imgur.com/9fGQwoy.png)

### Project Setting
指定 plug-in 格式、類型、及其接口。
點擊左上方小齒輪 ->  
![](https://i.imgur.com/WCR6AuX.png)

### Debug Setting

[How to debug with JUCE Audio Plugin Host C++](https://www.youtube.com/watch?v=8G7MvRdljLc&ab_channel=MuscledBeard)

## 合成器實作
在合成器中實作四款常見波形：  
![](https://i.imgur.com/hyf3uzv.png)

#### SynthVoice.cpp
### 正弦波
```cpp=
float value = std::sin(currentAngle) * level * tailOff; //Sine wave
```

### 方波
```cpp=
float value = (std::sin(currentAngle) >= 0 ? 1 : -1) * level * tailOff; //Square wave
```
### 三角波
```cpp=
float value = std::asin(std::sin(currentAngle)) * level * tailOff; //Triangle wave
```

### 鋸齒波

```cpp=
float value = std::atan(std::tan(currentAngle)) * level * tailOff; //Sawtooth wave
```



## 開發過程遇到的困難


### Debug Setting
原本照著[教學影片](https://www.youtube.com/watch?v=8G7MvRdljLc&ab_channel=MuscledBeard)進行專案的除錯命令設定，但在 JUCE 資料夾中找不到 AudioPluginHost.exe，僅有兩類似檔案
- JUCE/extras/AudioPluginHost/AudioPluginHost.jucer
- JUCE/extras/AudioPluginHost/Builds/VisualStudio2017/AudioPluginHost.sln

然將此兩檔案加入除錯命令 VS 皆會報錯，經查詢才發現 Build the solution 即可得到 executable，也就順利能搭配 Plugin Host 進行 Debug 了。


### Audio Plugin Testing
自己做好的 Plug-in 在測試時並不會隨內建 Plug-in 一同出現在新增選項中，而解決方法如[官方文件](https://docs.juce.com/master/tutorial_create_projucer_basic_plugin.html)：
> Pressing "Cmd-P" (or going to Options > Edit the List of Available Plug-ins...) will allow you to update the list of plug-ins on your system (you will only have to do this once per project). 
> Click the options button at the bottom of the pop-up window and click Scan for new or updated VST3 plug-ins. 
> On Windows you will need to manually copy the VST3 you built from your project's build folder to the VST3 installation folder


### 對 HackMD 不熟悉
這個禮拜看著 [課程簡介](https://hackmd.io/@datuiji/AnalysisOfDigitalMusicSignal/https%3A%2F%2Fhackmd.io%2F%40datuiji%2FCourseIntroduction)，想著課堂上似乎有說明須將 Sine 波改成其他波型，卻怎麼也找不到作業說明，也不見同學們在下方作業區上傳開發紀錄
仍正納悶之時，才發現原來左側可以展開目錄，尋尋覓覓的作業說明、Q&A、繳交區，其實早就都放在這裡了！

然而，屋漏偏逢連夜雨，就在我糊塗之時，作業截止日期也悄然成為歷史。只能說，不經一事，不長一智，未來如果有不明白的地方一定要積極詢問才好。

## Reference
[課程內容 @datuiji](https://hackmd.io/@datuiji/AnalysisOfDigitalMusicSignal/https%3A%2F%2Fhackmd.io%2F%40datuiji%2FJUCEFrameWorkSetting)
[JUCE Tutorial](https://juce.com/learn/tutorials)
[How to debug with JUCE Audio Plugin Host C++](https://www.youtube.com/watch?v=8G7MvRdljLc&ab_channel=MuscledBeard)
[常見波形](https://en.wikipedia.org/wiki/Waveform)
