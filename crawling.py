import requests
import re
from bs4 import BeautifulSoup

url2 = ["https://snshealth.ansan.go.kr/hcGuide/maternalChildhood/ChildbirthEncouragement.jsp?menuId=06004012"]
url = ["http://snshealth.ansan.go.kr/hcGuide/fundholding/Fundholding.jsp?menuId=06004039",
       "http://snshealth.ansan.go.kr/hcGuide/fundholding/Obstinacy.jsp?menuId=06004039", "http://snshealth.ansan.go.kr/hcGuide/fundholding/Hepatitis.jsp?menuId=06004039", "http://snshealth.ansan.go.kr/hcGuide/fundholding/Premature.jsp?menuId=06004039", "http://snshealth.ansan.go.kr/hcGuide/fundholding/Apriority.jsp?menuId=06004039",
       "http://snshealth.ansan.go.kr/hcGuide/fundholding/Dementia.jsp?menuId=06004039", "http://snshealth.ansan.go.kr/hcGuide/fundholding/OldSurgery.jsp?menuId=06004039", "http://snshealth.ansan.go.kr/hcGuide/fundholding/OldEyeSurgery.jsp?menuId=06004039"]
num = 0


def tab_menu2(name, class_, submain, contents):
    if submain.name == name and submain.get('class') == class_:
        contents.append('<div class="tab_menu2">\n')
        contents.append('<ul class="clearfix">\n')
        for i in submain.select("li"):
            if i.get('class') != None and len(i.get('class')) != 0:
                if i.get('class')[0] == 'on':
                    i = i.find("a")
                    contents.append('<li class = "active">'
                                    + '<a href="' + i.get('href')
                                    + '">' + i.text + '</a></li>\n')
            else:
                i = i.find("a")
                contents.append('<li><a href="'
                                + i.get('href') + '">' + i.text
                                + '</a></li>\n')
        contents.append("</ul>\n</div>")
        return True
    return False


def tab_menu(name, class_, submain, contents):
    if submain.name == name and submain.get('class') == class_:
        contents.append('<div class="tab_menu">\n<div class="tab_contents divide4">\n')
        contents.append('<ul class="tab_list clearfix">\n')
        for i in submain.select("li"):
            if i.get('class') != None and len(i.get('class')) != 0:
                if i.get('class')[0] == 'on':
                    i = i.find("a")
                    contents.append('<li class = "active">'
                                    + '<a class="tab_btn" href="'
                                    + i.get('href') + '">' + i.text
                                    + '</a></li>\n')
            else:
                i = i.find("a")
                contents.append('<li><a class="tab_btn" href="'
                                + i.get('href') + '">' + i.text
                                + '</a></li>\n')
        contents.append("</ul>\n</div>\n</div>")
        return True
    return False


def btn(name, class_, submain, contents):
    if submain.name == name and submain.get('class') == class_:
        print(submain)
        for i in submain.select("li"):
            print(i)
            i = i.find("a")
            contents.append('<a title="새창" target="_blank" class="btn" href="'
                            + i.get('href') + '">' + i.text
                            + '</a>\n')
        contents.append("</ul>\n</div>\n</div>")
        return True
    return False
# regex를 반복적으로 할 수 있게 해주는 함수(ex : list)


def loop_sub(regex, sub, str, min, max, wrap_sub='{}'):
    for i in range(max, min - 1, -1):
        sub_total = ''

        group_count = sub.count('\g')
        for k in range(i):
            sub_temp = sub
            for j in range(1, group_count + 1):
                sub_temp = sub_temp.replace('\g<{}>'.format(
                    j), '\g<{}>'.format(j + group_count * k))
            sub_total += sub_temp

        sub_total = wrap_sub.format(sub_total)
        str = re.sub(regex * i, sub_total, str)

    return str


def make_templete(html, select_name):
    content = str(html.select(select_name)[0].prettify())

    # html tag 삭제
    content = re.sub('<!DOCTYPE[^>]*>', '', content)
    content = re.sub('<html[^>]*>', '', content)
    content = re.sub('</html[^>]*>', '', content)
    content = re.sub('<body[^>]*>', '', content)
    content = re.sub('</body[^>]*>', '', content)
    # 주석 삭제
    content = re.sub('\s*<!--[\s\S]*?-->\s*', '', content)
    content = re.sub('<br/>', '\n', content)
    # 스크립트 삭제
    content = re.sub('<script[^>]*>\s*[^>]*\s*</script>', '', content)
    # 내용 없는 태그 쌍 제거
    content = re.sub('<[^</>]*>\s*</[^</>]*>', '', content)
    # 라인 병합
    content = re.sub('<([^>]*)>\n*([^<]*)\n*</([^>]*)>', '<\g<1>>\g<2></\g<3>>', content)
    # 헤딩 변경
    content = re.sub('h4', 'h3', content)
    content = re.sub('h5', 'h4', content)
    content = re.sub('h6', 'h5', content)

    # 스타일 수정
    content = re.sub('<(?!col)(.*?)style=".*?"(.*?)(/?>)', '<\g<1>\g<2>\g<3>', content)
    # lang?? font?? 이거 삭제
    content = re.sub('<(.*?)lang=".*?"(.*?)(/?>)', '<\g<1>\g<2>\g<3>', content)

    # 클래스 수정 여기서 하세용
    content = re.sub('<ul class="(?!tabStyle)(?!ulStyle1 column4)(?!btnList).*?">',
                     '<ul class="bu">', content)
    # 모든 클래스 삭제 / 주의하시오
    content = re.sub('<(?!ul)([^>]*)class="(?!on)(?!btnList.).*?"(.*?)(/?>)',
                     '<\g<1>\g<2>\g<3>', content)
    # width, height, valign 샥제
    content = re.sub('[ \t]*(?:height|width|align|valign)=".*?"[ \t]*', ' ', content)
    content = re.sub('(alt=".*?")(.*?)(src=".*?")', '\g<3>\g<2>\g<1>', content)

    # 태그 수정
    # (\<div[^/>]*[\>])([^<]*)(\<\/div\>)
    # (\<[a-zA-Z]+[^/>]*[\>])([^<]*)(\<\/[a-zA-Z]+\>)
    # (\<([a-zA-Z]+[^/>]*)[\>])\s*(\<\/([a-zA-Z]+)\>)
    content = re.sub('</?div[^>]*(?!"btnList3")>\s*', '', content)
    content = re.sub('<span[^/>]*>', '', content)
    content = re.sub('</span[^\<>]*>', '', content)
    content = re.sub('<dt[^\<>]*>([^<]*)', '<h4>\g<1></h4>', content)
    content = re.sub('</dt[^\<>]*>', '', content)
    content = re.sub('<dd[^\<>]*>', '<li>', content)
    content = re.sub('</dd[^\<>]*>', '</li>', content)
    content = re.sub('<dl[^\<>]*>', '<ul class="bu">', content)
    content = re.sub('</dl[^\<>]*>', '</ul>', content)
    content = re.sub('(<ul[^>]*>)\s*(<h4>[^<]*</h4>)', '\g<2>\n\g<1>', content)

    # 이미지 박스 생성
    content = re.sub(
        '(<img[^>]*>)', '\n<span class="temp_imagebox">\n<span class="image">\g<1></span>\n</span>', content)

    # table 수정
    content = re.sub('<table[^</>]*>', '<table class="table">', content)
    content = re.sub('(<table[^</>]*>)\s*(?!<caption>)', '\g<1>\n<caption></caption>\n', content)
    # table scope 달기
    content = re.sub('<th(?!ead)([^>]*)>', '<th scope="col" \g<1>>', content)
    content = re.sub('(<th[^>]*>)\s*<strong>([^<]*)</strong>\s*</th>', '\g<1>\g<2></th>', content)
    content = re.sub('<th scope="col"([^>]*)>\s*([^<]*)\s*</th[^>]*>\s*<td([^>]*)>',
                     '<th scope="row" \g<1>>\g<2></th>\n<td\g<3>>', content)
    content = re.sub('(<td[^>]*>)\s*<p[^>]*>\s*([^<]*)\s*</p[^>]*>', '\g<1>\g<2>', content)
    # caption 보류
    # regex = re.compile(r'<table[^>]*>[.\s]*</table>')
    # # <th scope="col"[^>]*>([^<]*)</th[^>]*>')
    # thcols = regex.findall(content)
    # capnum = []
    # caption = []
    # for i in thcols:
    #     l = len(i) - 1
    #     while l >= 0:
    #         if i[l] == '|' or i[l] == ' ' or i[l] == '\n':
    #             t = i
    #             i = t[0: l]
    #             i += t[l + 1: len(t)]
    #         l = l - 1
    #     caption.append(i)
    # print(caption)

    # 라인 병합
    content = re.sub('<([^>]*)>\s*([^<]*)\s*</([^>]*)>', '<\g<1>>\g<2></\g<3>>', content)
    content = re.sub('\s+</([^>]*)>', '\n</\g<1>>', content)
    content = re.sub('<([^>]*)>\s+', '<\g<1>>\n', content)
    content = re.sub(
        '<(strong|a|li|p|u|td|th|h3|h4|h5)( ?[^>]*)>\s*([^<\n]*)\s*</(strong|a|li|p|u|td|th|h3|h4|h5)>', '<\g<1>\g<2>>\g<3></\g<4>>', content)

    # 아무것도 없는 공백 라인 삭제
    content = re.sub('(\n){2,}', '', content)
    content = re.sub('(\r\n){2,}', '\n', content)
    content = re.sub('(\n){2,}', '', content)
    content = re.sub('(\r\n){2,}', '\n', content)

    # -여러개를 ul>li로 and 하나를 p로
    content = loop_sub('(?:\n\s*[-ㆍ][ ]*(.*)\s*)', '<li>\g<1></li>\n',
                       content, 2, 10, '\n<ul>\n{}</ul>')
    content = re.sub('(?:\n\s*[-ㆍ][ ]*(.*)\s*)', '\n<p>\g<1></p>\n', content)
    content = re.sub('<ul[^>]*>\s*<li>([^<]*)</li>\s*</ul>', '<p class="blt">\g<1></p>', content)

    # h4태그 및에 p태그 ul>li로 바꿈
    # content = loop_sub('\n<p>(.*?)</p>', '\n<li>\g<1></li>',
    # content, 2, 15, '\n<ul class="bu">{}\n</ul>')
    return content


for u in url:
    num = num + 1
    r = requests.get(u)
    c = r.content
    html = BeautifulSoup(c, 'lxml')
    content = make_templete(html, '.subMain')
    content = BeautifulSoup(content, 'html.parser')
    origin = content
    loc = html.find("ul", class_="location")
    loc = loc.find("li", class_="on").text
    title = html.find(name="div", class_="subTop")
    title = title.find(name="h3").find(name="span")
    if title != None:
        title = title.text
        i = len(title) - 1
        while i >= 0:
            if title[i] == '|' or title[i] == ' ':
                t = title
                title = t[0: i]
                title += t[i + 1: len(t)]
            i = i - 1
    else:
        title = num

    contents = []
    for submain in origin:
        ch1 = False
        ch2 = False
        ch3 = False
        ch4 = False
        ch1 = tab_menu("ul", ['tabStyle'], submain, contents)
        ch2 = tab_menu2("ul", ['ulStyle1', 'column4'], submain, contents)
        ch3 = btn("ul", ['btnList'], submain, contents)
        ch4 = btn("div", ['btnList3'], submain, contents)
        if (not ch1) and (not ch2) and (not ch3) and (not ch4):
            contents.append(submain)
    f = open("보건사업안내→" + loc + "→" + str(title) + ".html", 'w', encoding="UTF8")
    for i in contents:
        f.write(str(i))
    print("create file 보건사업안내→" + loc + "→" + str(title) + ".html")
    f.close()
