from pathlib import Path

from reportlab.lib.colors import HexColor
from reportlab.lib.pagesizes import A4
from reportlab.lib.styles import ParagraphStyle, getSampleStyleSheet
from reportlab.lib.units import mm
from reportlab.platypus import ListFlowable, ListItem, Paragraph, SimpleDocTemplate, Spacer


OUTPUT_PATH = Path("/Users/jueta/Documents/Projects/CDJ/output/pdf/cdj-app-summary.pdf")


def bullet_list(items, style, left_indent=10):
    return ListFlowable(
        [ListItem(Paragraph(item, style)) for item in items],
        bulletType="bullet",
        start="circle",
        leftIndent=left_indent,
        bulletFontName="Helvetica",
        bulletFontSize=7,
        bulletOffsetY=1,
    )


def build_pdf() -> None:
    OUTPUT_PATH.parent.mkdir(parents=True, exist_ok=True)

    doc = SimpleDocTemplate(
        str(OUTPUT_PATH),
        pagesize=A4,
        leftMargin=14 * mm,
        rightMargin=14 * mm,
        topMargin=12 * mm,
        bottomMargin=10 * mm,
        title="CDJ App Summary",
        author="OpenAI Codex",
    )

    styles = getSampleStyleSheet()
    title_style = ParagraphStyle(
        "Title",
        parent=styles["Title"],
        fontName="Helvetica-Bold",
        fontSize=18,
        leading=21,
        textColor=HexColor("#16324F"),
        spaceAfter=6,
    )
    section_style = ParagraphStyle(
        "Section",
        parent=styles["Heading2"],
        fontName="Helvetica-Bold",
        fontSize=9.5,
        leading=11,
        textColor=HexColor("#1F5C74"),
        spaceBefore=4,
        spaceAfter=2,
    )
    body_style = ParagraphStyle(
        "Body",
        parent=styles["BodyText"],
        fontName="Helvetica",
        fontSize=8.7,
        leading=10.6,
        textColor=HexColor("#202124"),
        spaceAfter=2,
    )
    bullet_style = ParagraphStyle(
        "Bullet",
        parent=body_style,
        fontSize=8.4,
        leading=10.0,
        leftIndent=0,
        spaceAfter=0,
    )
    small_style = ParagraphStyle(
        "Small",
        parent=body_style,
        fontSize=7.2,
        leading=8.4,
        textColor=HexColor("#5F6368"),
    )

    what_it_is = (
        "A custom DIY CDJ-style DJ controller project built around a Sparkfun Pro Micro "
        "(ATmega328p @ 16 MHz) with USB-MIDI firmware, hardware design assets, and a Mixxx mapping. "
        "The repo combines firmware, mapping files, docs, and a Fusion 360 model for a computer-connected DJ control surface."
    )
    who_its_for = (
        "Primary persona: a DIY maker or DJ tech hobbyist who wants to build, flash, and use a custom two-deck "
        "USB-MIDI controller with desktop DJ software such as Mixxx."
    )
    key_features = [
        "USB-MIDI firmware using Arduino plus the <font name='Helvetica-Bold'>MIDIUSB</font> library.",
        "Two-deck transport and looping controls, including play/pause and cue.",
        "Fifteen analog controls through a <font name='Helvetica-Bold'>74HC4067</font> multiplexer for EQ, gain, filter, tempo, and mixer/master values.",
        "Sixteen extra button inputs through a <font name='Helvetica-Bold'>PCF8575</font> I2C GPIO expander.",
        "Three rotary encoders for two jog wheels plus a music-selection encoder.",
        "Mixxx integration via <font name='Helvetica-Bold'>DJC-DIY.midi.xml</font> and <font name='Helvetica-Bold'>DJC-DIY-scripts.js</font>.",
        "Hardware design context included via photos, pinout docs, and <font name='Helvetica-Bold'>CDJv2.f3z</font>.",
    ]
    architecture = [
        "<font name='Helvetica-Bold'>Input layer:</font> buttons on a PCF8575, three direct INPUT_PULLUP buttons, three rotary encoders, and up to 15 pots through a 74HC4067 feeding A0.",
        "<font name='Helvetica-Bold'>Firmware layer:</font> <font name='Helvetica-Bold'>CDJ_firmware/src/main.cpp</font> polls I2C, digital pins, encoders, and mux channels, then emits USB-MIDI note and CC messages with <font name='Helvetica-Bold'>MIDIUSB</font>.",
        "<font name='Helvetica-Bold'>Host integration:</font> Mixxx mapping files translate incoming MIDI into deck actions such as play, cue, loop, jog, playlist load, and playlist scroll.",
        "<font name='Helvetica-Bold'>Service layer:</font> Not found in repo. No backend, cloud service, or database is present.",
        "<font name='Helvetica-Bold'>Data flow:</font> physical controls -> Pro Micro firmware -> USB-MIDI over USB -> Mixxx XML/JS mapping -> DJ software deck/playlist actions.",
    ]
    run_steps = [
        "Install PlatformIO in VS Code. <font name='Helvetica-Bold'>Not found in repo:</font> a lockfile or automated bootstrap script.",
        "Open <font name='Helvetica-Bold'>/Users/jueta/Documents/Projects/CDJ/CDJ_firmware</font> and connect the Sparkfun Pro Micro by USB.",
        "Build/upload with <font name='Helvetica-Bold'>pio run --target upload</font>.",
        "Copy <font name='Helvetica-Bold'>DJC-DIY.midi.xml</font> and <font name='Helvetica-Bold'>DJC-DIY-scripts.js</font> into Mixxx's mappings folder, then launch Mixxx.",
        "Launch Mixxx, connect the controller, and enable or refine the mapping as needed.",
    ]

    story = [
        Paragraph("CDJ App Summary", title_style),
        Paragraph("What It Is", section_style),
        Paragraph(what_it_is, body_style),
        Paragraph("Who It's For", section_style),
        Paragraph(who_its_for, body_style),
        Paragraph("What It Does", section_style),
        bullet_list(key_features, bullet_style, left_indent=11),
        Spacer(1, 2),
        Paragraph("How It Works", section_style),
        bullet_list(architecture, bullet_style, left_indent=11),
        Spacer(1, 2),
        Paragraph("How To Run", section_style),
        bullet_list(run_steps, bullet_style, left_indent=11),
        Spacer(1, 3),
        Paragraph(
            "Repo evidence used: readme.md, docs/FIRMWARE.md, docs/HARDWARE.md, docs/PINOUT.md, "
            "docs/MIXXX.md, CDJ_firmware/src/main.cpp, CDJ_firmware/platformio.ini, "
            "CDJ_firmware/mixx_Mapping/DJC-DIY.midi.xml, and CDJ_firmware/mixx_Mapping/DJC-DIY-scripts.js.",
            small_style,
        ),
    ]

    def draw_page_background(canvas, _doc):
        canvas.saveState()
        canvas.setFillColor(HexColor("#FFFFFF"))
        canvas.rect(0, 0, A4[0], A4[1], stroke=0, fill=1)
        canvas.restoreState()

    doc.build(story, onFirstPage=draw_page_background)


if __name__ == "__main__":
    build_pdf()
