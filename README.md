# Ai-import tkinter as tk
from tkinter import ttk, filedialog, messagebox
import os
import psutil
import subprocess

class MyToolkit:
    def __init__(self, root):
        self.root = root
        self.root.title("나만의 컴퓨터 활용 도구 (202644064 이동욱)")
        self.root.geometry("600x500")

        # 탭 메뉴 구성
        tab_control = ttk.Notebook(root)
        
        self.tab1 = ttk.Frame(tab_control)
        self.tab2 = ttk.Frame(tab_control)
        self.tab3 = ttk.Frame(tab_control)
        
        tab_control.add(self.tab1, text='파일 관리')
        tab_control.add(self.tab2, text='시스템 정보')
        tab_control.add(self.tab3, text='프로세스 관리')
        tab_control.pack(expand=1, fill="both")

        self.setup_tab1() # 확장자 변경
        self.setup_tab2() # 설치 프로그램 목록
        self.setup_tab3() # 실행 프로세스 목록

    # --- 기능 1: 확장자 일괄 변경 ---
    def setup_tab1(self):
        label = tk.Label(self.tab1, text="확장자 일괄 변경 도구", font=('Arial', 12, 'bold'))
        label.pack(pady=10)

        self.dir_path = tk.StringVar()
        tk.Entry(self.tab1, textvariable=self.dir_path, width=50).pack(pady=5)
        tk.Button(self.tab1, text="폴더 선택", command=self.select_dir).pack()

        tk.Label(self.tab1, text="현재 확장자 (예: txt)").pack()
        self.old_ext = tk.Entry(self.tab1)
        self.old_ext.pack()

        tk.Label(self.tab1, text="변경할 확장자 (예: pdf)").pack()
        self.new_ext = tk.Entry(self.tab1)
        self.new_ext.pack()

        tk.Button(self.tab1, text="실행", command=self.change_extensions, bg="lightblue").pack(pady=10)

    def select_dir(self):
        path = filedialog.askdirectory()
        self.dir_path.set(path)

    def change_extensions(self):
        path = self.dir_path.get()
        old = self.old_ext.get()
        new = self.new_ext.get()
        
        count = 0
        for filename in os.listdir(path):
            if filename.endswith(f".{old}"):
                base = os.path.splitext(filename)[0]
                os.rename(os.path.join(path, filename), os.path.join(path, f"{base}.{new}"))
                count += 1
        messagebox.showinfo("완료", f"{count}개의 파일 확장자를 변경했습니다.")

    # --- 기능 2: 설치 프로그램 목록 출력 ---
    def setup_tab2(self):
        tk.Label(self.tab2, text="설치된 프로그램 목록 추출", font=('Arial', 12, 'bold')).pack(pady=10)
        self.txt_list = tk.Text(self.tab2, height=15)
        self.txt_list.pack(padx=10, pady=10)
        
        tk.Button(self.tab2, text="목록 불러오기", command=self.get_installed_apps).pack()

    def get_installed_apps(self):
        # 윈도우 레지스트리 등을 조회해야 하지만, 간단히 PowerShell 명령어로 구현
        self.txt_list.delete(1.0, tk.END)
        try:
            cmd = 'powershell "Get-ItemProperty HKLM:\\Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\* | Select-Object DisplayName"'
            output = subprocess.check_output(cmd, shell=True).decode('cp949')
            self.txt_list.insert(tk.END, output)
        except:
            self.txt_list.insert(tk.END, "목록을 불러오는데 실패했습니다.")

    # --- 기능 3: 실행 중인 프로세스 목록 ---
    def setup_tab3(self):
        tk.Label(self.tab3, text="실행 중인 프로세스 목록", font=('Arial', 12, 'bold')).pack(pady=10)
        self.proc_list = tk.Listbox(self.tab3, width=70, height=15)
        self.proc_list.pack(padx=10, pady=10)
        
        tk.Button(self.tab3, text="새로고침", command=self.update_processes).pack()

    def update_processes(self):
        self.proc_list.delete(0, tk.END)
        for proc in psutil.process_iter(['pid', 'name']):
            try:
                self.proc_list.insert(tk.END, f"PID: {proc.info['pid']} - Name: {proc.info['name']}")
            except (psutil.NoSuchProcess, psutil.AccessDenied):
                pass

if __name__ == "__main__":
    root = tk.Tk()
    app = MyToolkit(root)
    root.mainloop()
