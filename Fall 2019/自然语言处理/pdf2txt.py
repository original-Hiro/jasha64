from pdfminer.pdfparser import PDFParser
from pdfminer.pdfdocument import PDFDocument
from pdfminer.pdfpage import PDFPage
from pdfminer.pdfpage import PDFTextExtractionNotAllowed
from pdfminer.pdfinterp import PDFResourceManager
from pdfminer.pdfinterp import PDFPageInterpreter
from pdfminer.pdfdevice import PDFDevice
from pdfminer.layout import *
from pdfminer.converter import PDFPageAggregator
import sys

def Pdf2Txt(path):
    # 打开文件
    fp = open(path, 'rb')
    #来创建一个pdf文档分析器
    parser = PDFParser(fp)
    #创建一个PDF文档对象存储文档结构
    document = PDFDocument(parser)
    # 检查文件是否允许文本提取
    if not document.is_extractable:
        raise PDFTextExtractionNotAllowed
    else:
        # 创建一个PDF资源管理器对象来存储共赏资源
        rsrcmgr=PDFResourceManager()
        # 设定参数进行分析
        laparams=LAParams()
        # 创建一个PDF设备对象
        # device=PDFDevice(rsrcmgr)
        device=PDFPageAggregator(rsrcmgr,laparams=laparams)
        # 创建一个PDF解释器对象
        interpreter=PDFPageInterpreter(rsrcmgr,device)
        # 处理每一页
        paragraph = ''
        paragraph_list = []
        print('[Start get all pdf pages content...]')
        for page_no, page in enumerate(PDFPage.create_pages(document)):
            print('[Get content of page %d ...]'%(page_no+1))
            interpreter.process_page(page)
            # 接受该页面的LTPage对象
            layout=device.get_result()
            layout_size = len(layout)
            for i,x in enumerate(layout):
                try:
                    if(isinstance(x,LTTextBox)):
                        for xx in x:
                            content = xx.get_text().strip()
                            if paragraph != '' and paragraph[-1] == '-':
                                paragraph = paragraph[:-1] + content
                            else:
                                paragraph += ' ' + content
                        paragraph = paragraph.strip()

                        # 去除带论文商标的段落
                        if paragraph.find('©') != -1:
                            paragraph = ''
                            continue
                        # 去除纯数字的段落
                        if paragraph.isdigit():
                            paragraph = paragraph_list[-1] + ' '
                            del paragraph_list[-1]
                            continue
                        paragraph_list.append(paragraph)
                        paragraph = ''
                except Exception as e:
                    print(str(e))
                    print("Failed!")
        print('')
    fp.close()
    return paragraph_list

def transfer(paragraph_list, Save_path):
    # 创建空文件
    print('[Create empty file...]')
    with open('%s'%(Save_path),'w', encoding='utf-8') as f:
        pass
    # 写入文件
    print('[Writing all paragraph...]')
    with open('%s'%(Save_path),'a', encoding='utf-8') as f:
        for i, paragraph in enumerate(paragraph_list):
            print('[Writing paragraph %d...]'%(i+1))
            
            # 写入英文段落
            f.write(paragraph)
            f.write('\n\n')

    print('[The translated document has been written to local.]')

if __name__ == '__main__':
    filename = sys.argv[1]

    paragraph_list = Pdf2Txt(filename)
    transfer(paragraph_list,'%s.txt'%filename)
