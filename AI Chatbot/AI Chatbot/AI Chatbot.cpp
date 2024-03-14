#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Chatbot 
{
public:
	virtual std::string respond(const std::string& input) = 0;
};
class SimpleChatbot : public Chatbot 
{
public:
	std::string respond(const std::string& input) override 
{
	// Simple responses based on keywords
	if (input.find("hello") != std::string::npos || input.find("hi") != std::string::npos) 
{
	return "Hello! How can I assist you today?";
}
	else if (input.find("how are you") != std::string::npos) 
{
	return "I'm just a computer program, but thank you for asking!";
}
	else if (input.find("bye") != std::string::npos || input.find("goodbye") != std::string::npos) 
{
	return "Goodbye! Have a great day!";
}
	else 
{
	return "I'm sorry, I didn't understand that. Can you please rephrase?";
}
}
};
class AdvancedChatbot : public Chatbot 
{
public:
	std::string respond(const std::string& input) override 
{
	// Implement more sophisticated dialogue management and responses
	// For simplicity, let's return static responses for demonstration
	return "I'm an advanced chatbot. Unfortunately, I'm not fully implemented yet.";
}
};
int main() 
{
	std::cout << "Welcome to the AI Chatbot!\n";
	std::cout << "Choose chatbot type (1 - Simple, 2 - Advanced): ";
	int choice;
	std::cin >> choice;
	Chatbot* chatbot = nullptr;
	if (choice == 1) 
{
	chatbot = new SimpleChatbot();
}
	else if (choice == 2) 
{
	chatbot = new AdvancedChatbot();
}
	else 
{
	std::cout << "Invalid choice. Exiting...\n";
	return 1;
}
	std::cin.ignore(); // Clear input buffer
	while (true) 
{
	std::cout << "You: ";
	std::string input;
	std::getline(std::cin, input);
	if (input.empty()) 
{
	std::cout << "Chatbot: Please say something.\n";
	continue;
}
	if (input == "exit") 
{
	break;
}
	std::cout << "Chatbot: " << chatbot->respond(input) << std::endl;
}
	delete chatbot;
	return 0;
}