<?php
/**
 * @file
 * This template handles the layout of cj_balloon style.
 */

if (is_array($settings['border'])) {
  // Make sure we set the right border width and color.
  if (!isset($settings['border']['color'])) {
    $color = 'black';
  }
  elseif ($settings['border']['color'] == 'other') {
    $color = $settings['border']['custom_color'];
  }
  else {
    $color = $settings['border']['color'];
  }

  if (!isset($settings['border']['width'])) {
    $border = '1px';
  }
  elseif ($settings['border']['color'] == 'other') {
    $border = $settings['border']['custom_border_width'];
  }
  else {
    $border = $settings['border']['width'];
  }
}
else {
  if (!isset($settings['color'])) {
    $color = 'black';
  }
  elseif ($settings['color'] == 'other') {
    $color = $settings['custom_color'];
  }
  else {
    $color = $settings['color'];
  }

  if (!isset($settings['width'])) {
    $border = '1px';
  }
  elseif ($settings['color'] == 'other') {
    $border = $settings['custom_border_width'];
  }
  else {
    $border = $settings['border'];
  }
}


?>

<?php if (isset($settings['well']['well_modifier'])): ?>
  <?php print 'style="border:'; ?> <?php print $border; ?> solid <?php print $color; ?><?php print '"'; ?>
<?php else: ?>
  <div class="border" style="border: <?php print $border; ?> solid <?php print $color; ?>; padding: 10px;">
    <?php print render($content); ?>
  </div>
<?php endif; ?>
