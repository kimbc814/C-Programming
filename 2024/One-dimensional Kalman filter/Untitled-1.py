import openpyxl

def read_text_file(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        data = file.readlines()
    return data

def write_to_excel(data_list, excel_path, cell_ranges):
    wb = openpyxl.load_workbook(excel_path)
    sheet = wb.active
    
    for data, cell_range in zip(data_list, cell_ranges):
        start_row, start_col = cell_range[0], cell_range[1]
        for i, line in enumerate(data, start=start_row):
            line = line.strip().split(',')
            for j, value in enumerate(line, start=start_col):
                cell = sheet.cell(row=i, column=j)
                cell.value = float(value) if '.' in value else int(value)
                
    wb.save(excel_path)

# 텍스트 파일 경로 리스트
text_file_paths = [
    "C:/Users/pc_01/Desktop/output1.txt",
    "C:/Users/pc_01/Desktop/output2.txt",
    "C:/Users/pc_01/Desktop/output3.txt"
]

# 셀 범위 리스트
cell_ranges = [(2, 3), (2, 5), (2, 7)]  # 각 파일별로 해당하는 시작 셀의 행과 열 인덱스

# 텍스트 파일 읽기
text_data_list = [read_text_file(file_path) for file_path in text_file_paths]

# 엑셀 파일 경로
excel_file_path = "C:/Users/pc_01/Desktop/position_data.xlsx"

# 엑셀에 데이터 쓰기
write_to_excel(text_data_list, excel_file_path, cell_ranges)
