#include <Arduino.h>
#include <WiFi.h>
#include <ESPmDNS.h>

// WiFi 연결에 필요한 SSID와 비밀번호를 정의
const char* ssid = "여기에_WiFi_이름을_입력하세요";
const char* password = "여기에_WiFi_비밀번호를_입력하세요";

void setup(void) {
    Serial.begin(115200);  // 시리얼 통신 초기화 (통신 속도: 115200bps)
    
    // WiFi 모드를 스테이션 모드로 설정 (WIFI_STA: 클라이언트로 작동)
    WiFi.mode(WIFI_STA);  
    WiFi.begin(ssid, password);  // 정의된 SSID와 비밀번호로 WiFi에 연결 시도
    Serial.println("");          // 시리얼 모니터에서 보기 쉽게 한 줄 추가

    // WiFi 연결을 기다림
    while (WiFi.status() != WL_CONNECTED) {  // WiFi가 연결될 때까지 계속 대기
        delay(500);        // 0.5초 대기
        Serial.print("."); // 연결 시도 중임을 표시하기 위해 점을 출력
    }
    Serial.println(""); 
    Serial.print("Connected to "); Serial.println(ssid);  // 연결된 네트워크 이름 출력
    Serial.print("IP address: "); Serial.println(WiFi.localIP());  // 장치의 로컬 IP 주소 출력

    // mDNS 서비스 시작
    if (MDNS.begin("miniwifi")) {  // mDNS 이름을 'miniwifi'로 설정 --> (miniwifi.local)   http://miniwifi.local  URL형식으로 네트워크 접근 가능
        Serial.println("MDNS responder started");  // mDNS responder가 시작되었음을 알림
    }
}

void loop(void) {
    // 이 코드는 setup() 함수에서 설정된 후 반복적으로 실행됨.
    // 현재 loop()는 비어 있어서 특별한 작업을 하지 않음.
}