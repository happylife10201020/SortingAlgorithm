import subprocess
import time
import os
from colorama import init, Fore, Style

init(autoreset=True)

NUM_ITERATIONS = 1_000
success_count = 0
fail_count = 0
failed_inputs = []

def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

def draw_bar(success, fail):
    total = success + fail
    bar_width = 50
    if total == 0:
        success_ratio = 0
    else:
        success_ratio = int((success / total) * bar_width)
    fail_ratio = bar_width - success_ratio

    bar = (
            Fore.GREEN + "■" * success_ratio +
            Fore.RED + "■" * fail_ratio +
            Style.RESET_ALL
    )
    print(f"\n✅ 성공: {success}   ❌ 실패: {fail}")
    print(f"[{bar}]")

def read_input_file():
    try:
        with open("input.txt", "r") as f:
            return f.read()
    except:
        return "(input.txt 읽기 실패)"

for i in range(NUM_ITERATIONS):
    clear_screen()
    print(f"🔁 테스트 {i+1}/{NUM_ITERATIONS} 시작")

    try:
        subprocess.run(["python", "generate_input.py"], check=True)
        subprocess.run(["main.exe"], check=True)
        subprocess.run(["python", "check_output.py"], check=True)
        success_count += 1
    except subprocess.CalledProcessError:
        fail_count += 1
        failed_inputs.append(read_input_file())

    draw_bar(success_count, fail_count)
    time.sleep(0.5)

# 테스트 종료 후 실패한 input 출력
if failed_inputs:
    print("\n❌ 실패한 테스트 input.txt 내용:")
    for idx, content in enumerate(failed_inputs):
        print(f"\n📄 실패 #{idx+1}:\n{content}")
else:
    print("\n🎉 모든 테스트가 성공적으로 완료되었습니다!")

input("\n 테스트가 종료되었습니다. Enter 키를 누르면 창이 닫힙니다...")