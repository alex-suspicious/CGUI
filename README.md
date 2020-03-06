# CGUI
Some c++ headers to draw gui on windows console with buttons, labels, and etc...

IT'S ALPHA! 
I just started working on it!

At this time it's can draw background, buttons and labels, all buttons works.

and yeah, i should work on optimization.

https://imgur.com/CeZ5c5W

Some classes:

    ( cgui::cColor - can store color )
    (EXAMPLE)
cgui::cColor CLR(255,255,255);
COLORREF LCR_REF = CLR.GetREF()


    ( cgmath::Vector2 - can store 2d vector )
    (EXAMPLE)
cgmath::Vector2 VEC(0,0);
VEC = cgmath::Vector2(800,600);


    ( cgui::cWindow - used to easily acces to console window, resize console, etc )
    (EXAMPLE)
cgui::cWindow WIN( cgmath::Vector2(800,600) ) - create window class, and win size
WIN.SetBgColor( cgui::cColor ) - set background color
WIN.Update() - Update window
WIN.Clear() - Clear window

Use it like this:

cgui::cWindow WIN( cgmath::Vector2(800,600) );
WIN.SetBgColor( cgui::cColor(236, 233,216) );
while (1) {
  WIN.Update(); 
  WIN.Clear();
}
      
      
    ( cgui::cButton - just a button )
    (EXAMPLE)
cgui::cButton BTN;
BTN.SetPos - Set position of button
BTN.SetSize - Set size of button
BTN.SetColor( cgui::cColor ) - SetColor
BTN.SetText( LPCTSTR ) - Text of button
BTN.Update( cgui::cWindow ) - update button
BTN.Hover() - check if mouse hover on button, and change collor when it happens
BTN.Pressed() - check if mouse pressed on button, and change collor when it happens

Use it like this:

BTN.Update( cgui::cWindow );
BTN.Hover();

if ( BTN.Pressed() ) {
  BTN.SetPos( cgmath::Vector2(100 + rand() % 800 / 2, 100 + rand() % 600 / 2) )
}


    ( cgui::cLabel - just a label )
    (EXAMPLE)
cgui::cLabel LABL;
LABL.SetText( LPCTSTR ) - Set text of Label
LABL.SetPos( cgmath::Vector2 ) - Set position of Label
LABL.SetSize( cgmath::Vector2 ) - Set size of Label
LABL.Update( cgui::cWindow ) - update Label
