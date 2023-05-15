#include <Layout.hpp>
#include <Button.hpp>
#include <ImageView.hpp>
#include <EditText.hpp>
#include <iostream>

int main()
{
    Layout layout;

    Button* btn = new Button({12, 14}, {120, 45}, "This is test text.");
    ImageView* img = new ImageView({123, 20}, {120, 60}, "C:/test/test/tst.img");
    EditText* txtFld = new EditText({600, 40}, {120, 20}, InputType::password);
    EditText* nmbFld = new EditText({600, 40}, {120, 20}, InputType::decimalNumber);

    layout.addView(btn);
    layout.addView(img);
    layout.addView(txtFld);
    layout.addView(nmbFld);

    std::cout << layout.toXml() << std::endl;
}