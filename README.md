# 🕹️ C++ Console Minigame Project

> **C++ 기반 콘솔 미니게임 포트폴리오 프로젝트**  
> 기능별 시스템 분리, Smart Pointer 기반 메모리 관리,  
> 명확한 Update Cycle 설계를 중심으로 유지보수성과 확장성을 고려하여 구현했습니다.

---

## 📌 Project Summary

- **Language**: C++ (C++17)
- **Platform**: Console
- **Purpose**  
  객체 수명 관리, 시스템 아키텍처 분리, 논리 흐름 설계 역량을 보여주기 위한  
  학습 및 포트폴리오용 프로젝트



## 🧱 Architecture Overview

기능별 책임 분리를 중심으로 설계된 구조입니다.
```md
GameManager
├── Player
├── Monster
├── Map
├── CombatSystem
├── CollisionSystem
└── HudSystem
```

### Design Principles

- Single Responsibility Principle (SRP)
- Loose Coupling
- Clear Ownership & Lifetime Management

각 시스템은 자신의 책임만을 가지며,  
`GameManager`가 전체 게임 흐름을 제어합니다.

---

## 🔄 Update Cycle Design

모든 주요 객체는 동일한 Update 단계를 따릅니다.

```cpp
BeginUpdate();
Update();
EndUpdate();
Intent
BeginUpdate
상태 초기화 및 Update 전 준비 작업

Update
핵심 게임 로직 처리

EndUpdate
후처리 및 상태 정리

→ 로직 추가 시 어느 단계에 구현해야 하는지 명확히 판단할 수 있도록 설계되었습니다.
```
## 🧠 Memory Management Strategy
Smart Pointer Usage
std::shared_ptr
객체의 소유권 및 수명 관리

std::weak_ptr
객체 참조 접근 (순환 참조 방지)

Benefits
명확한 객체 생명주기 관리

메모리 누수 방지

각 시스템 클래스는 객체를 소유하지 않고 참조만 수행합니다.

## ✅ Strengths
1️⃣ Smart Pointer 기반 안정적인 메모리 관리
shared_ptr / weak_ptr 역할 분리

순환 참조 없는 구조

객체 수명 관리 명확

2️⃣ 시스템 단위 아키텍처 분리
Combat / Collision / HUD 등 기능별 책임 분리

단일 책임 원칙 적용

기능 확장 시 영향 범위 최소화

3️⃣ 명확한 Update 흐름 구조
Begin / Update / End 단계 분리

로직 위치 파악 용이

상태 관리 실수 감소

4️⃣ 코드 리뷰 기반 개선 가능 구조
논리 오류 및 유지보수 리스크 식별 가능

개선 방향이 명확한 코드 구조
