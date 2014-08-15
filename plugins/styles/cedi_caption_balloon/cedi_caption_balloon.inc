<?php
/**
 * @file
 * Definition of the cedi balloon style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Caption Balloon'),
  'description' => t('Renders the text pane in a caption balloon.'),
  'render pane' => 'cedi_caption_balloon_style_render_pane',
  'pane settings form' => 'cedi_caption_balloon_style_pane_settings_form',
  'panes' => TRUE,
  'regions' => FALSE,
  'hook theme' => array(
    'cedi_caption_balloon' => array(
      'variables' => array('content' => NULL, 'settings' => NULL),
      'path' => drupal_get_path('module', 'cedi_styles') . '/plugins/styles/cedi_caption_balloon',
      'template' => 'cedi-caption-balloon',
    ),
  ),
);

/**
 * Render callback for a single pane.
 *
 * NOTE: Must use theme_* here.
 */
function theme_cedi_caption_balloon_style_render_pane(&$vars) {
  $content = $vars['content'];
  $settings = $vars['settings'];

  if (empty($content->content)) {
    return;
  }

  // Get the fields that could be involved here.
  $fields_instances = cedi_styles_panels_styles_get_fields($vars);

  foreach ($fields_instances as $field => $instance) {
    switch ($field) {
      case 'field_basic_text_text':
        $settings['text'] = $content->content[$field];
        $settings['is_text'] = TRUE;
        break;
      case 'field_basic_image_caption':
        $settings['text'] = $content->content[$field];
        unset($content->content[$field]);
        $settings['is_image'] = TRUE;
        break;
//      default:
//        $settings['text'] = t('Your text will go here.');
//        $settings['preview'] = TRUE;
//        break;
    }

  }

  // Add style css.
  drupal_add_css($vars['style']['path'] .  '/' . $vars['style']['name'] . '.css');

  // Render the pane as normal
  $output = theme('panels_pane', array('content' => $content, 'pane' => $vars['pane'], 'display' => $vars['display']));

  // Theme the pane and add the ribbon.
  return theme('cedi_caption_balloon', array('content' => $output, 'settings' => $settings));
}

/**
 * Edit form callback.
 */
function cedi_caption_balloon_style_pane_settings_form($settings) {

  $form['left'] = array(
    '#type' => 'textfield',
    '#title' => t('Left'),
    '#description' => t('Enter a numeric value to move the caption balloon.'),
    '#default_value' => (isset($settings['left']) ? $settings['left'] : 0),
  );
  $form['top'] = array(
    '#type' => 'textfield',
    '#title' => t('Top'),
    '#description' => t('Enter a numeric value to move the caption balloon.'),
    '#default_value' => (isset($settings['top']) ? $settings['top'] : 0),
  );
  return $form;
}
