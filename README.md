# WiFi_Station

ESP32를 WiFi 스테이션(클라이언트) 모드로 공유기에 연결하고 mDNS 이름을 등록하는 기초 실습 예제.

## 개요

ESP32가 지정한 공유기에 접속할 때까지 기다린 뒤, 연결된 네트워크 이름과 할당받은 IP 주소를 시리얼 모니터에 출력한다. 이어서 mDNS 응답기를 `miniwifi`라는 이름으로 시작해 같은 네트워크에서 `miniwifi.local`로 장치를 찾을 수 있게 한다. `loop()`는 비어 있으며, 이후 HTTP 클라이언트·웹 서버 실습의 출발점이 되는 코드다.

## 하드웨어

- 보드: ESP32 DOIT DevKit V1 (`esp32doit-devkit-v1`)
- 외부 센서·액추에이터 없음

## 동작 방식

1. `Serial.begin(115200)`으로 시리얼 초기화
2. `WiFi.mode(WIFI_STA)` 후 `WiFi.begin(ssid, password)`로 접속 시도
3. 연결될 때까지 0.5초마다 `.`을 출력하며 대기
4. 연결되면 SSID와 로컬 IP 주소 출력
5. `MDNS.begin("miniwifi")` 성공 시 `MDNS responder started` 출력

## 개발 환경

- PlatformIO, platform `espressif32`, framework `arduino`
- 사용 라이브러리: `WiFi.h`, `ESPmDNS.h` (ESP32 Arduino 코어 내장)
- 업로드 속도 460800, 시리얼 모니터 속도 115200

## 설정

`src/main.cpp` 상단의 다음 상수를 자신의 WiFi 정보로 바꾼다.

- `ssid` : 접속할 WiFi 이름
- `password` : WiFi 비밀번호

## 빌드 및 실행

```bash
pio run -t upload
pio device monitor -b 115200
```

## 폴더 구조

```
WiFi_Station/
├── platformio.ini   # 보드·프레임워크·속도 설정
└── src/
    └── main.cpp     # WiFi 접속 + mDNS 시작
```
